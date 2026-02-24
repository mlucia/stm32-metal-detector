//включение и отключение зуммера.
    void zum_on_off(){ 
   boolean flag = 1;
   boolean an = 1;
   while(flag){
     but = digitalRead(SW);
     if (but == 1){flag = 0;}
     delay(10);}
   FastLED.clear();
   if (spk_on == 1){
   for (byte i = 0; i < NUM_LEDS; i++){ leds[i] = CHSV(color, 0, 0);}
   FastLED.show();
   digitalWrite(buzzer,1);
   delay(100);
   digitalWrite(buzzer,0);}
   else { for (byte i = 0; i < NUM_LEDS; i++){ leds[i] = CHSV(color, 0, 0);}
   FastLED.show();}
  flag = 1;
  while(flag){
  a = digitalRead(A);
    if(a==0){
    while(an){a = digitalRead(A);
    if(a == 1){an=0;}}
    bb = digitalRead(B);
    FastLED.clear();
    if(bb == 0){spk_on = 1;
      digitalWrite(buzzer,1);
      delay(100);
      digitalWrite(buzzer,0);
      for (byte i = 0; i < NUM_LEDS; i++){ leds[i] = CHSV(0, color, 0);}}
    else {spk_on = 0;
     for (byte i = 0; i < NUM_LEDS; i++){ leds[i] = CHSV(color, 0, 0);}}
    an = 1;
    FastLED.show();
    delay(10);}
    delay(10);
  but = digitalRead(SW);
  if (but == 0){flag = 0;
     FastLED.clear();
     FastLED.show();}}}
