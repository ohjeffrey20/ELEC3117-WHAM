# ELEC3117-WHAM
Full final code for the WHAM, a project for ELEC3117 at UNSW

## Uses
ALL code was written by Andrew Luo and Jeffrey Oh, with the exception of:
* esp8266.h
* esp8266.c

The above is an open source library by Camil Staps, to use the esp8266. It is important to note, so changes were made to this code to better match our needs.

## Code contents
* DHT11.c includes code for the temperature/humidty sensor
* LCD.c includes code for the LCD
* main.c includes initialisations, the interrupt handler and the main code loop
* Pulse.c includes code for the heart rate sensor
* Wifi.c includes code for uploading data to thingspeak
