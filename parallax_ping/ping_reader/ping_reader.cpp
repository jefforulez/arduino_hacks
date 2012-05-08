
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


#include "ping_reader.h"

//
// constants
//

// ping sensor pin
const int PING_SIGNAL_PIN = 7 ;

//
//
//

void setup()
{
	Serial.begin( 9600 ) ;
}

void loop()
{
	//
	// prime the sensor
	//
	pinMode( PING_SIGNAL_PIN, OUTPUT ) ;

	digitalWrite( PING_SIGNAL_PIN, LOW ) ;
	delayMicroseconds( 2 ) ;
	digitalWrite( PING_SIGNAL_PIN, HIGH ) ;
	delayMicroseconds( 5 ) ;
	digitalWrite( PING_SIGNAL_PIN, LOW ) ;

	//
	// read the sensor
	//
	pinMode( PING_SIGNAL_PIN, INPUT ) ;

	int ping = pulseIn( PING_SIGNAL_PIN, HIGH ) ;

	Serial.print( "ping: " ) ;
	Serial.print( ping ) ;
	Serial.println() ;

	// delay the loop
	delay( 1000 ) ;
}

