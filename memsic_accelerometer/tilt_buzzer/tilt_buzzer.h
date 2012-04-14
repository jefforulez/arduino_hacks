
//
// tilt buzzer
//
// simple hack which shows and sounds an alarm when an accelerometer detects tilt
//
// author: @jefforulez
//

//
//  ideas code and ideas stolen from:
//
// - http://www.instructables.com/id/Play-the-French-Can-Can-Using-an-Arduino-and-Buzze/
// - http://www.arduino.cc/en/Tutorial/AccelerometerMemsic2125
//


#ifndef rulez_tilt_buzzer_h
#define rulez_tilt_buzzer_h

// includes
#include <Arduino.h>
#include <inttypes.h>
#include <avr/pgmspace.h>

// functions
void toggleAlertLED( bool red ) ;

void soundBuzzer() ;

void playNote( long frequency ) ;
void playNote( long frequency, long duration, long pause ) ;

#endif
