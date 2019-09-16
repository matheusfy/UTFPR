/*  NRF24L01 Slave
 *  Joao Tavares
 *  2019 May 30th
 */
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9,10);

const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

typedef enum { role_ping_out = 1, role_pong_back } role_e;

const char* role_friendly_name[] = { "invalid", "Ping out", "Pong back"};

role_e role = role_pong_back;

void setup(void)
{
  Serial.begin(57600);
  radio.begin();
  radio.setRetries(15,15);
  radio.openReadingPipe(1,pipes[1]);
  radio.startListening();
  radio.printDetails();
  radio.openWritingPipe(pipes[1]);
  radio.openReadingPipe(1,pipes[0]);
  radio.startListening();
}

void loop(void)
{
  if ( radio.available() )
  {
    unsigned long data = 0;
    radio.read( &data, sizeof(unsigned long) );
    Serial.println(data);

    delay(20);
  }
}
