//настройка чувствительности.
void encoder(){ 
  boolean flag = 1;
  boolean an = 1;
  byte digit = 8;
  int count = 0;
  while(flag){
   a = digitalRead(A);
   if(a==0){while(an){a = digitalRead(A);
   if(a==1){an=0;}}
   an = 1;
   count = 0;
   bb = digitalRead(B);
   if(bb == 0){digitalWrite(buzzer,spk_on);
   calibr = calibr - set_size;
   digit = digit + 1;
   if(digit >= 8){digit = 0;}}
   else {digitalWrite(buzzer,spk_on);
   calibr = calibr + set_size;
   if(digit == 0){digit = 8;}
   digit = digit - 1;}
   FastLED.clear();
   leds[digit] = CHSV(color,0,0);
   FastLED.show();}
   delay(10);
   if(count == 0){digitalWrite(buzzer,0);}
   count = count + 1;
   if(count == 100){flag = 0;
   FastLED.clear();
   FastLED.show();}
  }}
