//Applying a pulse to the coil and measuring the duration of the EMF pulse.
    void impuls(){
  digitalWrite(pulse,0);
  delayMicroseconds(puls);//Default coil pulse duration is 120 μs.
  digitalWrite(pulse,1);

  // Wait for the Rising Edge (Start of pulse)
while (!MyTim->getCaptureCompare(1)) {
  // Optional: Add a timeout here so the code doesn't hang 
  // if the coil is disconnected.
}

// Reset the flag by reading the value (Standard STM32 behavior)
MyTim->getCaptureCompare(1);

// Re-initialize the counter to 0 immediately
MyTim->setCount(0); 

// Wait for the Falling Edge (End of pulse/decay)
while (!MyTim->getCaptureCompare(2)) {
  // The timer is counting up at 36MHz while we wait here
}

// Capture the final count
// This value * 27.7ns = the duration of the decay
data1 = MyTim->getCaptureCompare(2); 

// Clear the flag for the next cycle
MyTim->getCaptureCompare(2);
  // while ( !Timer2.getInputCaptureFlag(TIMER_CH1) );//A loop until a rising edge capture occurs; if there is no signal (e.g., if the coil is disconnected), it will hang here.
  // Timer2.getCompare(TIMER_CH1);//Reset the flag
  // Timer2.refresh();//Reset the counter and count down to the low level.
  // while( !Timer2.getInputCaptureFlag(TIMER_CH2) );//Loop until falling edge
  //   data1 =  Timer2.getCompare(TIMER_CH2);//Save the counter value
  }
