
//
// pumpkinbot 2014
//
// hack o'lantern 2014
//
// author: @jefforulez
//

//
// parallax rfid code borrowed from
//
// https://github.com/ril3y/Make-Projects/blob/master/Arduino_Parallax_RFID_Reader/Arduino_Parallax_RFID_Reader.pde
//

#include "pumpkinbot2014_cc.h"

//
// RFID variables
//

const int LED_PIN = 13 ;

const int RFID_ENABLE = 8 ;

const int CODE_LEN         = 10   ; // max length of RFID tag
const int VALIDATE_LENGTH  = 200  ; // maximum reads b/w tag read and validate
const char START_BYTE      = 0x0A ;
const char STOP_BYTE       = 0x0D ;

const char candySourPatchKids[] = "_FIX_ME_" ;

char tag[CODE_LEN] ;

SoftwareSerial serialRFID( 6, 7) ; // RX, TX

//
// TTS variables
//

const int emic2RxPin = 2 ;
const int emic2TxPin = 3 ;

SoftwareSerial emic2Serial = SoftwareSerial( emic2RxPin, emic2TxPin ) ;
Emic2TtsModule emic2TtsModule = Emic2TtsModule( &emic2Serial ) ;

//
// methods
//

void setup()
{
	Serial.begin( 9600 ) ;
	Serial.println( "setup()" ) ;

	//
	// configure leds
	//

	pinMode( LED_PIN, OUTPUT ) ;

	//
	// configure RFID
	//

	serialRFID.begin( 2400 ) ;
	pinMode( RFID_ENABLE, OUTPUT ) ;

	//
	// configure TTS
	//

	pinMode( emic2RxPin, INPUT ) ;
	pinMode( emic2TxPin, OUTPUT ) ;
	emic2Serial.begin( 9600 ) ;
	emic2TtsModule.init() ;
	emic2TtsModule.setVolume( 40 ) ;
	emic2TtsModule.setWordsPerMinute( 200 ) ;
	emic2TtsModule.setVoice( PerfectPaul ) ;
	emic2TtsModule.say( F("Initializing") ) ;
	
	//
}

bool has_candy_last = true ;

void loop()
{
	
	if ( getRFIDTag() )
	{
		Serial.println( tag ) ;
		
		if ( 
			( strcmp( tag, candySourPatchKids ) != 0 ) &&
			! has_candy_last
		) {
			emic2TtsModule.say( F("That's not my candy!") ) ;
		}
		else
		{	
			ledsOff() ;
			has_candy_last = true ;
		}
	}
	else
	{
		ledsOn() ;
		has_candy_last = false ;
		
		emic2TtsModule.say( F("Give me candy!") ) ;
	}

	delay( 1000 ) ;
}

void ledsOn()
{
	digitalWrite( LED_PIN, LOW ) ;
}

void ledsOff()
{
	digitalWrite( LED_PIN, HIGH ) ;
}

//
//
// RFID
//
//

bool getRFIDTag() 
{
	for( int i = 0 ; i < CODE_LEN ; i++ ) {
		tag[i] = 0x0 ;
	}

	serialRFID.begin( 2400 ) ;
	serialRFID.flush() ;
	
	digitalWrite( RFID_ENABLE, LOW ) ;
	ledsOn() ;

	for ( int i = 0 ; i < 10 ; ++i )
	{
		if ( serialRFID.available() > 0 ) {
			break ;
		}
		delay( 50 ) ;
	}

	if ( serialRFID.available() <= 0 ) {
		digitalWrite( RFID_ENABLE, HIGH ) ;
		return false ;
	}
	
	byte next_byte = 0x0 ;
		
	//
	// throw away garbage bytes and wait for the start_byte
	//
	
	int max_loops = 10 ;
		
	while ( 
		serialRFID.available() >= 0 &&
		( next_byte = serialRFID.read() ) != START_BYTE && 
		--max_loops > 0
	)
	{
		serialRFID.read() ;
		delay( 100 ) ;
	}
	
	byte bytesread = 0 ;

	while ( 
		serialRFID.available() > 0 &&
		bytesread < CODE_LEN 
	) 
	{
		if ( ( next_byte = serialRFID.read() ) == STOP_BYTE) {
			break ;
		}
			
		tag[ bytesread++ ] = next_byte ;
	}

	digitalWrite( RFID_ENABLE, HIGH ) ;
	ledsOff() ;
	
	serialRFID.flush() ;
	
	return true ;
}
