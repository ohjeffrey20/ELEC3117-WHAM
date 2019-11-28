/*
 * File:   DHT11.c
 * Author: Andrew Luo, Jeffrey Oh
 * Edited 18/11/19
 */

#include "DHT11.h"
#include "LCD.h"
#include "defines.h"

void    DHT11_main(void){
    volatile unsigned char CheckSum;
    volatile unsigned char value[10];
    
    DHT11_Start();  
    if (DHT11_CheckResponse()){
        Humidity = DHT11_ReadData();
        RH_Dec = DHT11_ReadData();
        Temperature = DHT11_ReadData();
        T_Dec = DHT11_ReadData();
        CheckSum = DHT11_ReadData();

        //Displaying data on LCD
        sprintf(value, "%d", Humidity);
        LCDstring_xy(0,4,value);
        sprintf(value, ".%d", RH_Dec);
        LCDstring(value);
        LCDprocess('%');

        sprintf(value,"%d",Temperature);
        LCDstring_xy(1,5,value);
        sprintf(value,".%d",T_Dec);
        LCDstring(value);
        LCDprocess(0xB0);
        LCDprocess('C');       
    } 

}

void    DHT11_Start(void) {
    DHT11_PIN_DIR = 0;  //Data pin = OUTPUT
    DHT11_PIN = 0;      //Send LOW pulse
    __delay_ms(18);     //Send LOW pulse for at least 18ms width
    DHT11_PIN = 1;      //Send HIGH pulse
    __delay_us(30);     //Send HIGH pulse for at least 20us width
    DHT11_PIN_DIR = 1;  //Data pin = INPUT
}

char    DHT11_CheckResponse(void){
    __delay_us(40);
    if (!DHT11_PIN) {
        __delay_us(80);
        if (DHT11_PIN) {
            __delay_us(50);
            return 1;
        }
    }
    return 0;
}

char    DHT11_ReadData(void){
    unsigned int i, k = 0;
    char DHT11_data = 0;
    for (i = 0; i < 8; i++) {
        k = 0;
        while(!DHT11_PIN) {   // wait till 0 pulse, this is start of data pulse 
            k++;
            if (k > 100) {
                Timeout = 1;
                break;
            }
            __delay_us(1);
        }      
        __delay_us(30);         
        if (DHT11_PIN) {           /* check whether data is 1 or 0 */    
            DHT11_data = ((DHT11_data << 1) | 1); 
        }   else {
            DHT11_data = (DHT11_data << 1);  
        }
        k = 0;
        while(DHT11_PIN) {      // wait till end of pulse
            k++;
            if (k > 100) {
                Timeout = 1;
                break;
            }
            __delay_us(1);    
        }         
    }
    return  DHT11_data;
}
