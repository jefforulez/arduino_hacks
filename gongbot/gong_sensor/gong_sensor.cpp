
//
// gong_sensor
//
// send gong sound level to receiver
//
// author: @jefforulez
//

#include "gong_sensor.h"

const int SENSOR_PIN = A0 ;

const int NUMBER_READINGS = 10 ;

int readings[ NUMBER_READINGS ] ;
int index = 0 ;
int total = 0 ;
int average = 0 ;

const int SENSOR_THRESHOLD = 3 ;

const unsigned long THROTTLE_MS = 1500 ;
unsigned long last_sent_ms = 0 ;
unsigned long current_ms = 0 ;

void setup()
{
	Serial.begin( 9600 ) ;
	
	for ( int thisReading = 0 ; thisReading < NUMBER_READINGS ; thisReading++ ) {
		readings[ thisReading ] = 0 ;
	}
}

void loop()
{
	int val = analogRead( SENSOR_PIN ) ;
	
	// update the total
	total = total - readings[ index ] ;
	readings[ index ] = val ;
	total = total + readings[ index ] ;

	// compute the average
	average = total / NUMBER_READINGS ;
	

	// print the average, with a throttle
	if ( average > SENSOR_THRESHOLD )
	{
		current_ms = millis() ;
		
		if ( ( current_ms - last_sent_ms ) > THROTTLE_MS )
		{
			Serial.println( average ) ;
			last_sent_ms = current_ms ;	
		}
	}
	
	// update the readings index
	index = index + 1 ;
	if ( index >= NUMBER_READINGS ) {
		index = 0 ;
	}

	//
	delay( 10 ) ;
}



