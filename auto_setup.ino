//автоподстройка времени,длительности импульса эдс.
     void del_1(){
   long s = 0;
   for (int i = 0; i<count_f; i ++){
   impuls();
   delay(delay_hz);
   s = s + data1;} 
   calibr = s/count_f;}
