/** 
 * A simple modem terminal.
 * 
 * This sketch simply proxies the serial port input and output
 * to the SIM800H chip on board of the ubirch #1. Makes it easy
 * to explore the AT command set.
 * 
 * Use a real serial terminal to access the ubirch #1:
 * 
 * $ screen /dev/cu.SLAB_USBtoUART 115200
 * 
 * Exchange the device with the one the Arduino IDE uses.
 * 
 * @author Matthias L. Jugel
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

#include<SoftwareSerial.h>

#define WATCHDOG 6
#define SIM800H_RX 2
#define SIM800H_TX 3

SoftwareSerial sim800h = SoftwareSerial(SIM800H_TX, SIM800H_RX);

void setup() {
  // disable the external watchdog
  pinMode(WATCHDOG, OUTPUT);

  // setup baud rates for serial and modem
  Serial.begin(115200);
  sim800h.begin(9600);
  
  cli();

  // reset the timer registers
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 16000000UL / 8 / 2 - 1;
  TCCR1B |= _BV(CS11); // prescale 8 selected
  TCCR1B |= _BV(WGM12); // CTC mode
  TIMSK1 |= _BV(OCIE1A); // timer compare interrupt

  sei();

  // query generic information and registration status
  Serial.println();
  sim800h.println("ATI;+CREG?");
}

// read what is available from the serial port and send to modem
ISR(TIMER1_COMPA_vect) {  
  while(Serial.available() > 0) sim800h.write(Serial.read());
}

// the main loop just reads the responses from the modem and
// writes them to the serial port
void loop() {
  while(sim800h.available() > 0) Serial.write(sim800h.read());
}
