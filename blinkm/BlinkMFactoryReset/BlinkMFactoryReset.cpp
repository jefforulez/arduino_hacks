
//
// blinkm factory reset
//
// simple script testing the BlinkM library
//
// author: @jefforulez
//

//
// uses my version of BlinkM_funcs converted to a c++ library
// http://code.google.com/p/blinkm-projects/
//

#include "BlinkMFactoryReset.h"

// #include <Wire.h>
#include <BlinkM.h>

// arduino setup func
void setup()
{

	// BlinkM connections to Arduino
	// PWR - -- gnd -- black -- Analog out 2
	// PWR + -- +5V -- red   -- Analog out 3
	// I2C d -- SDA -- green -- Analog in  4
	// I2C c -- SCK -- blue  -- Analog in  5
	//
	BlinkM_beginWithPower() ;

	// wait a bit for things to stabilize
	delay( 100 ) ;

	// factory reset
	BlinkM_doFactoryReset() ;
}

// arduino loop func
void loop()
{
	delay( 1000 ) ;
}
