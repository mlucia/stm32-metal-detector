//настройка яркости.
  void col_vol(){ 
   boolean flag = 1;
   boolean an = 1;
   while(flag){
     but = digitalRead(SW);
     if (but == 1){flag = 0;}
     delay(10);}
   FastLED.clear();

   //for (byte i = 0; i < NUM_LEDS; i++){ leds[i] = CHSV(color, 0, 0);}
  for (byte i = 0; i < NUM_LEDS; i++){ leds[i] = CHSV(color, 0, 0);}
   FastLED.show();
  flag = 1;
  delay(500);
  while(flag){
    a = digitalRead(A);
    if(a==0){
    while(an){a = digitalRead(A);
    if(a == 1){an=0;}}
    bb = digitalRead(B);
    if(bb == 0){
      if(color < 250){
      digitalWrite(buzzer,spk_on);
      color = color + 10;}}
    else {
      if(color > 10){
      digitalWrite(buzzer,spk_on);
      color = color - 10;}}
    an = 1;
    FastLED.clear();
    for (byte i = 0; i < NUM_LEDS; i++){ leds[i] = CHSV(color, 0, 0);}
    FastLED.show();
    delay(10);
    digitalWrite(buzzer,0);}
  delay(10);
  but = digitalRead(SW);
  if (but == 0){flag = 0;}}
   FastLED.clear();
   FastLED.show();}
