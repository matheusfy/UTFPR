/*  NRF24L01 Master
 *  Joao Tavares
 *  2019 May 30th
 */
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9,10);

const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
unsigned long command = 10;
String str = "0";

void setup()
{
  Serial.begin(57600);
  
  radio.begin();
  radio.setRetries(15,15);
  radio.openReadingPipe(1,pipes[1]);
  radio.startListening();
  radio.printDetails();
  radio.openWritingPipe(pipes[0]);
  radio.openReadingPipe(1,pipes[1]);
  radio.stopListening();
}

void loop(void)
{
  radio.stopListening();

  if(Serial.available())
    str = Serial.readStringUntil('\n');
  
  command = (unsigned long) str.toInt();
  //command = 10;
  radio.write( &command, sizeof(unsigned long) );

  radio.startListening();

  delay(1000);
}
