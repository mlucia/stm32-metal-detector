//настройка на крупные или мелкие мишени (растягиваем шкалу индикации).
void setup_size()
{
   boolean flag = 1; 
   while(flag){
     but = digitalRead(SW);
     if (but == 1){flag = 0;}
     delay(10);} 
  FastLED.clear();
  for (int i = 0; i<(digit_2 + 1); i ++){   
  leds[i] = CHSV(0,color,0); }
  FastLED.show();
  flag = 1;
  boolean an = 1;
  while(flag)
  {
   a = digitalRead(A);
   if(a==0){while(an){ a = digitalRead(A);
   if(a==1){an=0;}}
   an = 1;
   bb = digitalRead(B);
   if(bb == 0){digitalWrite(buzzer,spk_on);
   if(digit_2 < 7){
   digit_2 = digit_2 + 1;
   set_size = set_size *2;}}
   else {digitalWrite(buzzer,spk_on);
   if(digit_2 > 0){
   set_size = set_size/2;
   digit_2 = digit_2 - 1;}}
   FastLED.clear();
   for (int i = 0; i<(digit_2 + 1); i ++){
   leds[i] = CHSV(0,color,0);}
   FastLED.show();
   delay(10);
   digitalWrite(buzzer,0);}
   delay(10);
   but = digitalRead(SW);
   if(but == 0){flag = 0;
   FastLED.clear();
   FastLED.show();}}}
