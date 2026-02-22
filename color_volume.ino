//настройка яркости.
  void col_vol(){ 
   boolean flag = 1;
   boolean an = 1;
   while(flag){
     but = digitalRead(SW);
     if (but == 1){flag = 0;}
     delay(10);}
   pixels.clear();
   for (byte i = 0; i < 8; i++){pixels.setPixelColor(i, pixels.Color(color,0,0));}
   pixels.show();
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
      digitalWrite(zummer,on_zum);
      color = color + 10;}}
    else {
      if(color > 10){
      digitalWrite(zummer,on_zum);
      color = color - 10;}}
    an = 1;
    pixels.clear();
    for (byte i = 0; i < 8; i++){pixels.setPixelColor(i, pixels.Color(color,0,0));}
    pixels.show();
    delay(10);
    digitalWrite(zummer,0);}
  delay(10);
  but = digitalRead(SW);
  if (but == 0){flag = 0;}}
   pixels.clear();
   pixels.show();}
