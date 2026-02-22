//включение и отключение зуммера.
    void zum_on_off(){ 
   boolean flag = 1;
   boolean an = 1;
   while(flag){
     but = digitalRead(SW);
     if (but == 1){flag = 0;}
     delay(10);}
   pixels.clear();
   if (on_zum == 1){
   for (byte i = 0; i < 8; i++){pixels.setPixelColor(i, pixels.Color(0,color,0));}
   pixels.show();
   digitalWrite(zummer,1);
   delay(100);
   digitalWrite(zummer,0);}
   else { for (byte i = 0; i < 8; i++){pixels.setPixelColor(i, pixels.Color(color,0,0));}
   pixels.show();}
  flag = 1;
  while(flag){
  a = digitalRead(A);
    if(a==0){
    while(an){a = digitalRead(A);
    if(a == 1){an=0;}}
    bb = digitalRead(B);
    pixels.clear();
    if(bb == 0){on_zum = 1;
      digitalWrite(zummer,1);
      delay(100);
      digitalWrite(zummer,0);
      for (byte i = 0; i < 8; i++){pixels.setPixelColor(i, pixels.Color(0,color,0));}}
    else {on_zum = 0;
     for (byte i = 0; i < 8; i++){pixels.setPixelColor(i, pixels.Color(color,0,0));}}
    an = 1;
    pixels.show();
    delay(10);}
    delay(10);
  but = digitalRead(SW);
  if (but == 0){flag = 0;
     pixels.clear();
     pixels.show();}}}
