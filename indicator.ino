//световая и звуковая индикация.
void showDigit(){
   // сравниваем значения и выводим на индикацию.
    if (count_sensor == 0){
    if (data1 > calibr + 2 * set_size){
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(0,color,0));
    count_sensor = 11;}
    else {count_sensor = 0;
    pixels.clear();}}
    
    if (count_sensor == 1){
    if (data1 > calibr + 4 * set_size){
    pixels.clear();
    pixels.setPixelColor(1, pixels.Color(0,color,0));
    count_sensor = 12;}
    else {count_sensor = 0;
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(0,color,0));}}
    
    if (count_sensor == 2){
    if (data1 > calibr + 6 * set_size){
    pixels.clear();
    pixels.setPixelColor(2, pixels.Color(0,color,0));
    count_sensor = 13;}
    else {count_sensor = 1;
    pixels.clear();
    pixels.setPixelColor(1, pixels.Color(0,color,0));}}
    
    if (count_sensor == 3){
    if (data1 > calibr + 8 * set_size){
    pixels.clear();
    pixels.setPixelColor(3, pixels.Color(0,color,0));
    count_sensor = 14;}
    else {count_sensor = 2;
    pixels.clear();
    pixels.setPixelColor(2, pixels.Color(0,color,0));}}

    if (count_sensor == 4){
    if (data1 > calibr + 10 * set_size){
    pixels.clear();
    pixels.setPixelColor(4, pixels.Color(0,color,0));
    count_sensor = 15;}
    else {count_sensor = 3;
    pixels.clear();
    pixels.setPixelColor(3, pixels.Color(0,color,0));}}
    
    if (count_sensor == 5){
    if (data1 > calibr + 12 * set_size){
    pixels.clear();
    pixels.setPixelColor(5, pixels.Color(color,0,0));
    count_sensor = 16;}
    else {count_sensor = 4;
    pixels.clear();
    pixels.setPixelColor(4, pixels.Color(0,color,0));}}
    
    if (count_sensor == 6){
    if (data1 > calibr + 14 * set_size){
    pixels.clear();
    pixels.setPixelColor(6, pixels.Color(color,0,0));
    count_sensor = 17;}
    else {count_sensor = 5;
    pixels.clear();
    pixels.setPixelColor(5, pixels.Color(color,0,0));}}
    
    if (count_sensor == 7){
    if (data1 > calibr + 16 * set_size){
    pixels.clear();
    pixels.setPixelColor(7, pixels.Color(color,0,0));
    count_sensor = 17;}
    else {count_sensor = 6;
    pixels.clear();
    pixels.setPixelColor(6, pixels.Color(color,0,0));}}

    pixels.show();
    
    if (count_sensor == 11){count_sensor = 1;}
    if (count_sensor == 12){count_sensor = 2;}
    if (count_sensor == 13){count_sensor = 3;}
    if (count_sensor == 14){count_sensor = 4;}
    if (count_sensor == 15){count_sensor = 5;}
    if (count_sensor == 16){count_sensor = 6;}
    if (count_sensor == 17){count_sensor = 7;}
    
    digitalWrite(zummer,0);
    
    if (on_zum == 1){
    if (data1 > calibr + 6 * set_size){
    if (count_buz == 1){count_buz = 0;
    digitalWrite(zummer,1);}
    else {count_buz = 1;}}}}
