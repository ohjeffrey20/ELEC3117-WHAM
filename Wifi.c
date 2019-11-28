/*
 * File:   Wifi.c
 * Author: Andrew Luo, Jeffrey Oh
 * Edited 18/11/19
 */

#include "Wifi.h"
#include "esp8266.h"
#include "defines.h"
#include "LCD.h"

//Checks if ESP8266 is ready for connection
void    WIFI_init(void) {

    Initialize_ESP8266(); 
    
    /* Checks if module is detected*/
    clearDisplay();
    LCDstring("ESP not found");
    while (!esp8266_isStarted()); //wait till the ESP send back "OK"
    clearDisplay();
    LCDstring("ESP found");
    __delay_ms(500);
    
    _esp8266_print("AT+RST\r\n");
    __delay_ms(5000);
    _esp8266_print("ATE0\r\n");
    __delay_ms(500);
    
    /* Checks if module is detected*/
    do {
        clearDisplay();
        LCDstring("ESP not found");
    }
    while (!esp8266_isStarted()); //wait till the ESP send back "OK"
    clearDisplay();
    LCDstring("ESP found");
    __delay_ms(500);
    
    /* Module joins WIFI Station */
    esp8266_mode(1);
    clearDisplay();
    LCDstring("ESP set as WIFI");
    
    _esp8266_print("AT+CIPMUX=0\r\n");
    _esp8266_waitResponse();
    _esp8266_print("AT+CIPMODE=0\r\n");
    _esp8266_waitResponse();
    
    clearDisplay();
    LCDstring("Connecting to");
    LCDstring_xy(1,0,"WIFI...");
   
    _esp8266_print("AT+CWJAP=\"");
    _esp8266_print(SSID);
    _esp8266_print("\",\"");
    _esp8266_print(SSID_password);
    _esp8266_print("\"\r\n");
    _esp8266_waitResponse();
    
}

void    WIFI_main(void) {
    unsigned char status = 0;
    
    volatile unsigned char data[8], dataa[8], dataaa[8];
    
    volatile unsigned char temp = Temperature;
    sprintf(data, "%d", temp);

    volatile unsigned char humid = Humidity;
    sprintf(dataa, "%d", humid);
    
    bpm = BPM;
    volatile unsigned char beats = bpm;
    sprintf(dataaa, "%d", beats);
        

    clearDisplay();
    LCDstring("WIFI Connected");   
    
    //OK = 1
    _esp8266_print("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n");
    _esp8266_waitResponse();
    
    clearDisplay();
    LCDstring("Server Connected");   

    //OK = 1    
    _esp8266_print("AT+CIPSEND=");
    if (bpm >= 100) {
        _esp8266_print("71");
    } else {
        _esp8266_print("70");
    }
    _esp8266_print("\r\n");
    _esp8266_waitResponse();
    
    clearDisplay();
    LCDstring("Uploading Data");
    
    _esp8266_print("GET /update?api_key=J9N60X3XTH64MZAJ&field1=");
    _esp8266_print(data);
    _esp8266_print("&field2=");
    _esp8266_print(dataa); 
    _esp8266_print("&field3=");
    _esp8266_print(dataaa); 
    _esp8266_print("\r\n\r\n");
    _esp8266_waitResponse();   

    __delay_ms(5000);
    //__delay_ms(5000);

    clearDisplay();
    LCDstring("Data Uploaded");
    __delay_ms(1000);
}

