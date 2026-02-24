//световая и звуковая индикация.
void showDigit(){
   // сравниваем значения и выводим на индикацию.
    if (count_sensor == 0){
    if (data1 > calibr + 2 * set_size){
    FastLED.clear();
    leds[0] = CHSV(0,color,0);
    count_sensor = 11;}
    else {count_sensor = 0;
    FastLED.clear();}}
    
    if (count_sensor == 1){
    if (data1 > calibr + 4 * set_size){
    FastLED.clear();
    leds[1] = CHSV(0,color,0);
    count_sensor = 12;}
    else {count_sensor = 0;
    FastLED.clear();
    leds[0] = CHSV(0,color,0);}}
    
    if (count_sensor == 2){
      if (data1 > calibr + 6 * set_size){
         FastLED.clear();
      leds[2] =  CHSV(0,color,0);
      count_sensor = 13;
      }
      else {
         count_sensor = 1;
         FastLED.clear();
         leds[1] = CHSV(0,color,0);
      }
    }
    
    if (count_sensor == 3){
      if (data1 > calibr + 8 * set_size){
         FastLED.clear();
         leds[3] = CHSV(0,color,0);
         count_sensor = 14;
         }
      else {
         count_sensor = 2;
         FastLED.clear();
         leds[2] = CHSV(0,color,0);
      }
   }

    if (count_sensor == 4){
      if (data1 > calibr + 10 * set_size){
         FastLED.clear();
         leds[4] = CHSV(0,color,0);
         count_sensor = 15;
         }
      else {
         count_sensor = 3;
         FastLED.clear();
      leds[3] = CHSV(0,color,0);
      }
   }
    
    if (count_sensor == 5){
    if (data1 > calibr + 12 * set_size){
    FastLED.clear();
    leds[5] = CHSV(color,0,0);
    count_sensor = 16;}
    else {count_sensor = 4;
    FastLED.clear();
    leds[4] = CHSV(0,color,0);}}
    
    if (count_sensor == 6){
    if (data1 > calibr + 14 * set_size){
    FastLED.clear();
    leds[6] = CHSV(color,0,0);
    count_sensor = 17;}
    else {count_sensor = 5;
    FastLED.clear();
    leds[5] = CHSV(color,0,0);}}
    
    if (count_sensor == 7){
    if (data1 > calibr + 16 * set_size){
    FastLED.clear();
    leds[7] = CHSV(color,0,0);
    count_sensor = 17;}
    else {count_sensor = 6;
    FastLED.clear();
    leds[6] = CHSV(color,0,0); } }

    FastLED.show();
    
    if (count_sensor == 11){count_sensor = 1;}
    if (count_sensor == 12){count_sensor = 2;}
    if (count_sensor == 13){count_sensor = 3;}
    if (count_sensor == 14){count_sensor = 4;}
    if (count_sensor == 15){count_sensor = 5;}
    if (count_sensor == 16){count_sensor = 6;}
    if (count_sensor == 17){count_sensor = 7;}
    
    digitalWrite(buzzer,0);
    
    if (spk_on == 1){
    if (data1 > calibr + 6 * set_size){
    if (count_buz == 1){count_buz = 0;
    digitalWrite(buzzer,1);}
    else {count_buz = 1;}}}}
