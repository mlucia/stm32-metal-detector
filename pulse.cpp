//подача импульса на катушку и измерение длительности импульса эдс.
    void impuls(){
  digitalWrite(pulse,0);
  delayMicroseconds(puls);//подача импулса на катушку по умолчанию 120 мкс.
  digitalWrite(pulse,1);
  while ( !Timer2.getInputCaptureFlag(TIMER_CH1) );//цикл пока не сработает захват по переднему фронту,при отсутствии сигнала будет здесь висеть,например при отклбченной катушке.
  Timer2.getCompare(TIMER_CH1);//сбрасываем флаг
  Timer2.refresh();//обнуляем счетчик и считаем до нижнего уровня
  while( !Timer2.getInputCaptureFlag(TIMER_CH2) );//цикл до спада
  data1 =  Timer2.getCompare(TIMER_CH2);//записываем значение счетчика
  }
