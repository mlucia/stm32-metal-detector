//настройка на крупные или мелкие мишени (растягиваем шкалу индикации).
void setup_size()
{
   boolean flag = 1; 
   while(flag){
     but = digitalRead(SW);
     if (but == 1){flag = 0;}
     delay(10);} 
  pixels.clear();
  for (int i = 0; i<(digit_2 + 1); i ++){   
  pixels.setPixelColor(i, pixels.Color(0,color,0)); }
  pixels.show();
  flag = 1;
  boolean an = 1;
  while(flag)
  {
   a = digitalRead(A);
   if(a==0){while(an){ a = digitalRead(A);
   if(a==1){an=0;}}
   an = 1;
   bb = digitalRead(B);
   if(bb == 0){digitalWrite(zummer,on_zum);
   if(digit_2 < 7){
   digit_2 = digit_2 + 1;
   set_size = set_size *2;}}
   else {digitalWrite(zummer,on_zum);
   if(digit_2 > 0){
   set_size = set_size/2;
   digit_2 = digit_2 - 1;}}
   pixels.clear();
   for (int i = 0; i<(digit_2 + 1); i ++){
   pixels.setPixelColor(i, pixels.Color(0,color,0));}
   pixels.show();
   delay(10);
   digitalWrite(zummer,0);}
   delay(10);
   but = digitalRead(SW);
   if(but == 0){flag = 0;
   pixels.clear();
   pixels.show();}}}
