/* 
 * File: defines.h
 * Author: Andrew Luo, Jeffrey Oh
 * Edited 18/11/19
 */

#ifndef defines
#define defines

// #includes
#include <xc.h>
#include <pic16f1789.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

//**************************************************************
// * Global Variables
//**************************************************************
//Timer
extern volatile int TMR0count = 0;
extern volatile int TMR1count = 0;

extern volatile unsigned int bpm = 0;
extern volatile unsigned int BPM = 75;
extern volatile unsigned int bpmsum = 0;
extern volatile unsigned int bpmcount = 0;
extern volatile unsigned char Temperature = 0;
extern volatile unsigned char T_Dec = 0;
extern volatile unsigned char Humidity = 0;
extern volatile unsigned char RH_Dec = 0;
extern volatile unsigned char Info = 0;
extern volatile unsigned char Timeout = 0;

extern volatile unsigned char State = 0;
extern volatile unsigned char State_Temp = 0;

extern volatile unsigned char Count = 0;
extern volatile unsigned char DHT11_Count = 0;

extern volatile unsigned char State_IF = 0;

extern volatile unsigned char WIFI_Count = 0;
extern volatile unsigned char WIFI_Status = 0;

//**************************************************************
// *                        DEFINES
//**************************************************************

// General
#define _XTAL_FREQ 20000000  //8MHz External Crystal Oscillator
#define BUSY_LED RC4
#define BUSY_LED_TRIS TRISC4

// LCD
#define EN RD3 
#define RS RD2
//**************************************************************
//                          SENSORS

// Pulse
#define threshold 3        // TODO This value MUST change
extern volatile bool prev_low = true;
#define BPMH   100
#define BPML   40

// DHT11
#define DHT11_PIN RD0
#define DHT11_PIN_DIR   TRISD0
#define TEMPH   25
#define TEMPL   20
#define HUMH    60
#define HUML    40


//**************************************************************
//                           WIFI

//#define SSID            "andrew"
//#define SSID_password   "andrew23"
#define SSID            "OnePlus 7 Pro"
#define SSID_password   "Onepluspro"

#define TX RC6
#define RX RC7


// THINGSPEAK
#define SERVER          "184.106.153.149"
#define PORT            80

#define channelID       "872498"
#define APIWriteKey     "J9N60X3XTH64MZAJ"
#define APIWriteField   "GET https://api.thingspeak.com/update?api_key=J9N60X3XTH64MZAJ&fiel"

#endif




