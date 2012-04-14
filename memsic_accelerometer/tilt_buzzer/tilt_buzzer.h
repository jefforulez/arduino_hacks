
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
