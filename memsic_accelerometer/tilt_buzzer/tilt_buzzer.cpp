
#include "tilt_buzzer.h"

//
// constants
//

// output pins
const int LED_GREEN_PIN = 12 ;
const int LED_RED_PIN = 13 ;
const int BUZZER_PIN = 3 ;

// input pins
const int X_AXIS_PIN = 7 ;
const int Y_AXIS_PIN = 6 ;

// accelerometer tolerance
const int LEVEL_MIN = 4000 ; // 4900 ;
const int LEVEL_MAX = 5500 ; // 4980 ;

const long BUZZER_DURATION = 200 ;

//
// 
//

void setup() 
{
	Serial.begin( 9600 ) ;

	pinMode( LED_GREEN_PIN, OUTPUT ) ;
	pinMode( LED_RED_PIN, OUTPUT ) ;

	pinMode( BUZZER_PIN, OUTPUT ) ;

	pinMode( X_AXIS_PIN, INPUT ) ;
	pinMode( Y_AXIS_PIN, INPUT ) ;

}

void loop() 
{
	int x = pulseIn( X_AXIS_PIN, HIGH ) ;
	int y = pulseIn( Y_AXIS_PIN, HIGH ) ;
	
	if ( x < LEVEL_MIN || x > LEVEL_MAX )
	{	
		Serial.print( "x: " ) ;
		Serial.print( x ) ;	
		Serial.println() ;

		toggleLEDs( true ) ;

		soundBuzzer() ;
	}
	else if ( y < LEVEL_MIN || y > LEVEL_MAX ) 
	{
		Serial.print( "y: " ) ;
		Serial.print( y ) ;	
		Serial.println() ;

		toggleLEDs( true ) ;

		soundBuzzer() ;
	}
	else
	{
		toggleLEDs( false ) ;
		delay( 200 ) ;
	}

}

void soundBuzzer()
{
	// ideas from
	// http://www.instructables.com/id/Play-the-French-Can-Can-Using-an-Arduino-and-Buzze/
	//
	// using wavelengths from
	// http://www.phy.mtu.edu/~suits/notefreqs.html

	playNote( 2100 ) ;
	playNote( 1990 ) ;
	playNote( 1870 ) ;
	playNote( 1770 ) ;
	playNote( 1670 ) ;
}

void playNote( long frequency ) 
{
	playNote( frequency, BUZZER_DURATION, 0 ) ;
}

void playNote( long frequency, long duration, long pause = 0) 
{
	long delayValue = 1000000 / frequency / 2 ;
	long numCycles = frequency * duration / 1000 ;
	
	Serial.print( "frequency: " ) ;
	Serial.println( frequency ) ;
	Serial.print( "duration: " ) ;
	Serial.println( duration ) ;
	Serial.print( "numCycles: " ) ;
	Serial.println( numCycles ) ;
	Serial.print( "delayValue: " ) ;
	Serial.println( delayValue ) ;
	
	for ( long i = 0 ; i < numCycles ; ++i )
	{
		digitalWrite( BUZZER_PIN, HIGH ) ;
		delayMicroseconds( delayValue ) ;
		
		digitalWrite( BUZZER_PIN, LOW ) ;
		delayMicroseconds( delayValue ) ;
	}
}

void toggleLEDs( bool red )
{
	if ( red == true )
	{
		digitalWrite( LED_RED_PIN, HIGH ) ;
		digitalWrite( LED_GREEN_PIN, LOW ) ;
	}
	else
	{
		digitalWrite( LED_RED_PIN, LOW ) ;
		digitalWrite( LED_GREEN_PIN, HIGH ) ;
	}
}
