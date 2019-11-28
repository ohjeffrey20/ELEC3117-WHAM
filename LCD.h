/* 
 * File: LCD.h
 * Author: Andrew Luo, Jeffrey Oh
 * Edited 18/11/19
 */

#ifndef LCD
#define	LCD

void    LCD_init (void);
void    LCDpulse (void);
void    LCDprocess (volatile unsigned int data);
void    secondDisplay (void);
void    clearDisplay (void);
void    LCDstring (volatile unsigned char ch[]);    //Output string input
void    LCDstring_xy (int row, int col, volatile unsigned char ch[]); //Outputs string input in specified location
void    LCD_main (void);


#endif



