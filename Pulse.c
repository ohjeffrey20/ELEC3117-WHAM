/*
 * File:   Pulse.c
 * Author: Andrew Luo, Jeffrey Oh
 * Edited 18/11/19
 */

#include "defines.h"
#include "Pulse.h"
#include "LCD.h"
#include "DHT11.h"

void PULSE_main(void) {
    bpm = 0; 
    volatile unsigned char value[8] = {0};
    if (RA0 == 1 && prev_low) {   
        bpmsum += TMR1count;     
        TMR1count = 0;
        if (bpmcount == 10) {
            bpm = bpmsum / 12;
            if (bpm < (BPM - 5) || bpm > (BPM + 5)) {
                bpm = (bpm + BPM)/2;
            }
            sprintf(value, "%d", bpm);
            LCDstring_xy(0, 13, value);
            if (bpm < 100) {
                LCDprocess(' ');
            }
            bpmcount = 0;
            bpmsum = 0;
            BPM = bpm;
        }
        prev_low = false;
        __delay_ms(100);
        bpmcount++;
    }
    else {
        prev_low = true;
        __delay_ms(100);
    }
}