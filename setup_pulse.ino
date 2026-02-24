//настройка глубины обнаружения (длительность подачи импульса на катушку от 120 до 50 мкс).
void setup_pulse()
{
   boolean flag = 1; 
   while(flag){
     but = digitalRead(SW);
     if (but == 1){flag = 0;}
     delay(10);} 
  FastLED.clear();
  for (int i = 0; i<(digit + 1); i ++){   
  leds[i] = CHSV(0,0,color); }
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
   if(digit < 7){
   digit = digit + 1;
   puls = puls + 10;}}
   else {digitalWrite(buzzer,spk_on);
   if(digit > 0){
   puls = puls - 10;
   digit = digit - 1;}}
   FastLED.clear();
   for (int i = 0; i<(digit + 1); i ++){
   leds[i] = CHSV(0,0,color);}
   FastLED.show();
   delay(10);
   digitalWrite(buzzer,0);}
   delay(10);
   but = digitalRead(SW);
   if(but == 0){flag = 0;
   FastLED.clear();
   FastLED.show();}}}
