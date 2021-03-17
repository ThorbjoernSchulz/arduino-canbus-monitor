/*****************************************************************************************
* This is implementation of CAN BUS ASCII protocol based on LAWICEL v1.3 serial protocol
*  of CAN232/CANUSB device (http://www.can232.com/docs/can232_v3.pdf)
*
* Made for Arduino with Seeduino/ElecFreaks CAN BUS Shield based on MCP2515
*
* Copyright (C) 2015 Anton Viktorov <latonita@yandex.ru>
*                                    https://github.com/latonita/arduino-canbus-monitor
*
* This library is free software. You may use/redistribute it under The MIT License terms. 
*
*****************************************************************************************/

#include <SPI.h>
#include "mcp_can.h"
#include "can-232.h"
#include "SoftwareSerial.h"

void setup() {
  delay(2000);

  Serial.begin(LW232_DEFAULT_BAUD_RATE);      // default COM baud rate is 115200. 
    
  Can232::init(CAN_500KBPS, MCP_8MHz, true);  // set default rate you need here and clock frequency of CAN shield.
                                                // Typically it is 16MHz, but on some MCP2515 + TJA1050 it is 8Mhz
}

void loop() {
  Can232::loop();
}

void serialEvent() {
  Can232::serialEvent();
}
