/* 
 *  An interrupt example program.
 *  
 *  It sets up an interrupt at 1Hz which can be slowed down by using the interrupt divider.
 *  
 *  more info: https://sites.google.com/site/qeewiki/books/avr-guide/timers-on-the-atmega328
 *  
 * == LICENSE ==
 * Copyright 2015 ubirch GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
  */
#define LED 13
#define FREQ_DIVIDER 32

int toggleCounter = FREQ_DIVIDER;
int toggleState = HIGH;

void setup(){
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  cli();

  // clear interrupt register
  TCCR0A = 0;
  TCCR0B = 0;
  TCNT0 = 0;
  
  // timer mode = CTC
  TCCR0A |= (1 << WGM01);
  // set the ISR COMPA vect
  TIMSK0 |= (1 << OCIE0A);   
  // OCRn =  [ (clock_speed / Prescaler_value) * Desired_time_in_Seconds ] - 1
  OCR0A = (16*10^6) / 1024 - 1;
  // prescaler = 1024 (CS10+12)  
  TCCR0B |= (1 << CS10) | (1 << CS12);
  
  sei();

}

ISR(TIMER0_COMPA_vect){
  toggleCounter -= 1;
  if (toggleCounter < 0) {
    toggleCounter = FREQ_DIVIDER;
    interrupt();
  } 
}

void interrupt() {
  toggleState = toggleState == HIGH ? LOW : HIGH;
  digitalWrite(LED,toggleState);
}

void loop(){
  Serial.print("toggle counter: ");
  Serial.println(toggleCounter);
  delay(100);
}
