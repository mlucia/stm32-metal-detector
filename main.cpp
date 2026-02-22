#include <FastLED.h>
#include <Arduino.h>

//#include <EasyNeoPixels.h>

#define NUM_LEDS 8 
/*
 * Note. Library uses SPI1
 * Connect the WS2812B data input to MOSI on your board./
 * A7
  */
#define zummer PB10
#define A PB12
#define B PB13
#define SW PB14
#define pulse PB8

WS2812B pixels = WS2812B(NUM_LEDS);
volatile long data1 = 0;
boolean a = 0;
boolean bb = 0;
boolean but = 0;
byte delay_hz = 8;//at this value the frequency is 120 hertz.
long calibr = 0;
long summa = 0;
byte count_f = 20;//the number of cycles from which the average value is calculated.
byte color = 10;//indicator brightness (minimum by default)
boolean on_zum = 1;//Turn on sound indication (1-on, 0-off).
boolean count_buz = 0;
byte count_sensor = 0;
byte puls = 120;//длительность импульса на катушку,в мкс.
byte digit = 7;
byte digit_2 = 0;
byte set_size = 1;


void setup() {
pinMode(pulse,OUTPUT);
digitalWrite(pulse,1);
  pixels.begin();
  pixels.show();
pinMode(zummer,OUTPUT);
digitalWrite(zummer,0);
pinMode(A,INPUT_PULLUP);
pinMode(B,INPUT_PULLUP);
pinMode(SW,INPUT_PULLUP);
pinMode(PA0,INPUT);
Timer2.pause();//stop the timer before setting up
Timer2.setPrescaleFactor(2);//we set the timer prescaler to 1/36 microseconds ~ 27 nanoseconds
Timer2.setInputCaptureMode(TIMER_CH1, TIMER_IC_INPUT_DEFAULT);//channel1 timer2 (PA0)
Timer2.setInputCaptureMode(TIMER_CH2, TIMER_IC_INPUT_SWITCH);
Timer2.setPolarity(TIMER_CH2, 1);//falling edge trigger.
Timer2.setSlaveFlags( TIMER_SMCR_TS_TI1FP1 | TIMER_SMCR_SMS_RESET );// capture flags
Timer2.refresh(); // reset timer 
Timer2.getCompare(TIMER_CH1); // Clear the channel 1 capture flag.
Timer2.getCompare(TIMER_CH2); // Clear the channel 2 capture flag.
Timer2.resume(); // start the timer
  scan();
 del_1(); 
  scan();}

void loop() { 
  summa = 0; 
  for (int i = 0; i<count_f; i ++){ 
  impuls();
   summa = summa + data1;
   a = digitalRead(A); //querying the encoder.
     if (a==0){encoder();}
   but = digitalRead(SW);// we track the encoder press.
     if (but==0){
       digitalWrite(zummer,0);
       col_vol();
       zum_on_off();
       setup_pulse();
       setup_size();
       del_1();
       scan();}
  delay(delay_hz);}
   data1 = summa / count_f;//we calculate the average value of the EMF pulse duration.
    showDigit();}//display on the indicator.
