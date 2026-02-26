
#include <FastLED.h>
#include <HardwareTimer.h>
//#include <Arduino.h>


#define NUM_LEDS 8 
/*
 * Note. Library uses SPI1
 * Connect the WS2812B data input to MOSI on your board./
 * A7
  */
#define DATA_PIN PA7

// Define the array of leds
CRGB leds[NUM_LEDS];

// Time scaling factors for each component
// #define TIME_FACTOR_HUE 60
// #define TIME_FACTOR_SAT 100
// #define TIME_FACTOR_VAL 100

#define buzzer PB10 // speaker
#define A PB12 // encoder a
#define B PB13 // encoder b
#define SW PB14 // encoder sw
#define pulse PB8 // coil trigger pin

volatile long data1 = 0;
boolean a = 0;
boolean bb = 0;
boolean but = 0;
byte delay_hz = 8;//at this value the frequency is 120 hertz.
long calibr = 0;
long summa = 0;
byte count_f = 20;//the number of cycles from which the average value is calculated.
byte color = 10;//indicator brightness (minimum by default)
boolean spk_on = 1;//Turn on sound indication (1-on, 0-off).
boolean count_buz = 0;
byte count_sensor = 0;
byte puls = 120;//pulse width  - длительность импульса на катушку,в мкс.
byte digit = 7;
byte digit_2 = 0;
byte set_size = 1;

// Create a pointer for the timer object
HardwareTimer *MyTim;

void setup() {
pinMode(pulse,OUTPUT);
digitalWrite(pulse,1);

pinMode(buzzer,OUTPUT);
digitalWrite(buzzer,0);
pinMode(A,INPUT_PULLUP);
pinMode(B,INPUT_PULLUP);
pinMode(SW,INPUT_PULLUP);
pinMode(PA0,INPUT);

Serial.begin(115200);
FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS).setRgbw(RgbwDefault());
FastLED.setBrightness(128);  // Set global brightness to 50%
FastLED.clear();
FastLED.show();

// 1. Get the timer instance for TIM2
  // We use the pin name to automatically find the right timer/channel
  TIM_TypeDef *Instance = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(PA0), PinMap_PWM);
  uint32_t channel = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(PA0), PinMap_PWM));

  MyTim = new HardwareTimer(Instance);

  // 2. Configure the Timer
  MyTim->pause();

  // Prescaler: F103 usually runs at 72MHz. 
  // A factor of 2 gives 36MHz (approx 27.7ns per tick)
  MyTim->setPrescaleFactor(2);

  // Set Overflow to max to prevent premature reset during metal sensing
  MyTim->setOverflow(0xFFFF); 

  // 3. Configure Input Capture
  // Setup Channel 1 (PA0) as the primary input
  MyTim->setMode(channel, TIMER_INPUT_CAPTURE_RISING, PA0);

  // For metal detectors, we often need the "Slave Mode" reset 
  // This resets the counter automatically on the trigger edge
  // We access the underlying HAL handle for this specific hardware feature
  TIM_HandleTypeDef *htim = MyTim->getHandle();
  
  // Replicating: Timer2.setSlaveFlags( TIMER_SMCR_TS_TI1FP1 | TIMER_SMCR_SMS_RESET );
  htim->Instance->SMCR |= (TIM_TS_TI1FP1 | TIM_SLAVEMODE_RESET);

  // 4. Finalize and Start
  MyTim->refresh();
  
  // Clear any existing capture flags (Replacing getCompare)
  MyTim->getCaptureCompare(channel); 
  
  MyTim->resume();

// Timer2.pause();//stop the timer before setting up
// Timer2.setPrescaleFactor(2);//we set the timer prescaler to 1/36 microseconds ~ 27 nanoseconds
// Timer2.setInputCaptureMode(TIMER_CH1, TIMER_IC_INPUT_DEFAULT);//channel1 timer2 (PA0)
// Timer2.setInputCaptureMode(TIMER_CH2, TIMER_IC_INPUT_SWITCH);
// Timer2.setPolarity(TIMER_CH2, 1);//falling edge trigger.
// Timer2.setSlaveFlags( TIMER_SMCR_TS_TI1FP1 | TIMER_SMCR_SMS_RESET );// capture flags
// Timer2.refresh(); // reset timer 
// Timer2.getCompare(TIMER_CH1); // Clear the channel 1 capture flag.
// Timer2.getCompare(TIMER_CH2); // Clear the channel 2 capture flag.
// Timer2.resume(); // start the timer
  scan();
  del_1(); 
  scan();
}

void loop() { 
  summa = 0; 
  for (int i = 0; i<count_f; i ++){ 
  impuls();
   summa = summa + data1;
   a = digitalRead(A); //querying the encoder.
     if (a==0){encoder();}
   but = digitalRead(SW);// we track the encoder press.
     if (but==0){
       digitalWrite(buzzer,0);
       col_vol();
       zum_on_off();
       setup_pulse();
       setup_size();
       del_1();
       scan();}
  delay(delay_hz);}
   data1 = summa / count_f;//we calculate the average value of the EMF pulse duration.
    showDigit();}//display on the indicator.
