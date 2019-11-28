/**
 * C library for the ESP8266 WiFi module with a PIC microcontroller
 * Copyright (C) 2015 Camil Staps <info@camilstaps.nl>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *****************************************************************************
 *
 * File:    esp8266.h
 * Author:  Camil Staps <info@camilstaps.nl>
 * Website: http://github.com/camilstaps/ESP8266_PIC
 * Version: 0.1
 *
 * See:     esp8266.c
 *
 * This is the header file for the ESP8266 PIC18 library. It contains:
 *
 *  * Constants and bitmasks
 *  * Prototypes for functions that should be written by the user for his
 *    implementation
 *  * Prototypes for functions that can be used by the user
 *  * Prototypes for functions that are intended for internal use only
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "defines.h"


#ifndef ESP8266_H
#define	ESP8266_H

#ifdef	__cplusplus
extern "C" {
#endif

/** Some constants **/

#define ESP8266_STATION 0x01
#define ESP8266_SOFTAP 0x02

#define ESP8266_TCP 1
#define ESP8266_UDP 0

#define ESP8266_OK 1
#define ESP8266_READY 2
#define ESP8266_FAIL 3
#define ESP8266_NOCHANGE 4
#define ESP8266_LINKED 5
#define ESP8266_UNLINK 6
    
int len;
    
void Initialize_ESP8266(void);

/** Should be witten by the user for input from / output to the ESP module **/

void _esp8266_putch(unsigned char);
char _esp8266_getch(void);

/** Function prototypes **/

__bit esp8266_isStarted(void);        // Check if the module is started (AT)
__bit esp8266_restart(void);          // Restart module (AT+RST)
void esp8266_echoCmds(bool);        // Enabled/disable command echoing (ATE)

// WIFI Mode (station/softAP/station+softAP) (AT+CWMODE)
void esp8266_mode(unsigned char);

// Connect to AP (AT+CWJAP)
unsigned char esp8266_connect(unsigned char*, unsigned char*);

// Disconnect from AP (AT+CWQAP)
void esp8266_disconnect(void);

// Local IP (AT+CIFSR)
void esp8266_ip(void);

// Create connection (AT+CIPSTART)
__bit esp8266_start(unsigned char protocol, const char* ip, const char port);

// Send data (AT+CIPSEND)
__bit esp8266_send(unsigned char*);

// Receive data (+IPD)
void esp8266_receive(unsigned char*, uint16_t, bool);

/** Functions for internal use only **/

// Print a string to the output
void _esp8266_print(unsigned const char *);

// Wait for a certain string on the input
inline uint16_t _esp8266_waitFor(unsigned char *);
// Wait for any response on the input
inline unsigned char _esp8266_waitResponse(void);

unsigned char esp8266_config_softAP(unsigned char* softssid, unsigned char* softpass);

void esp8266_get_stationIP();
void _esp8266_enable_MUX();
void _esp8266_create_server();
void _esp8266_start_mail();
void _esp8266_End_mail();
void _esp8266_disconnect_SMPT2GO();
void _esp8266_connect_SMPT2GO();
void _esp8266_login_mail(unsigned char* mail_ID, unsigned char* mail_Pas);
      
void _esp8266_mail_sendID(unsigned char* send_ID);
void _esp8266_mail_recID(unsigned char* rec_ID);
void _esp8266_mail_subject(unsigned char* subject);
void _esp8266_mail_body(unsigned char* body);

#ifdef	__cplusplus
}
#endif

#endif	/* ESP8266_H */




