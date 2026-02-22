//индикация начало работы.
void scan(){
 byte digit1 = 3;
 byte digit = 4;
 byte r = 0;
 byte g = 0;
 byte b = 0; 
 for (int a=0;a<3;a++){
  if (a == 0){r = 200;
  g = 0;
  b = 0;}
  if (a == 1){g = 200;
  r = 0;
  b = 0;}
  if (a == 2){b = 200;
  g = 0;
  r = 0;}
  for(int i=0;i<4;i++){
  pixels.clear();
  pixels.setPixelColor(digit1, pixels.Color(r,g,b));
  pixels.setPixelColor(digit, pixels.Color(r,g,b));
  pixels.show();
  delay(100);
  digit1 = digit1-1;
  digit = digit +1;}
  
  for(int i=0;i<4;i++){
  digit1 = digit1 + 1;
  digit = digit - 1;
  pixels.clear();
  pixels.setPixelColor(digit1, pixels.Color(r,g,b));
  pixels.setPixelColor(digit, pixels.Color(r,g,b));
  pixels.show();
  delay(100);
}}
pixels.clear();
pixels.show();}
