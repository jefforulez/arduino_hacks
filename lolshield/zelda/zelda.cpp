
//
// zelda triforce
//
// flash the triforce on a lolshield
//
// author: @jefforulez
//

//
// based on lol shield library sample code
// http://code.google.com/p/lolshield/
//

#include "zelda.h"

//
//
//

uint16_t BitMap[][9] =
{
	{ 0, 64, 224, 496, 520, 1820, 4030, 8191, 0 }
};

//
//
//

void setup()
{
	LedSign::Init() ;
}

void loop()
{
	DisplayBitMap() ;

	// 3x : show for 0.5s, clear; pause for.2s
	for ( uint8_t i = 0 ; i < 3 ; ++i )
	{
		DisplayBitMap() ;
		delay( 500 ) ;

		LedSign::Clear( 0 ) ;
		delay( 200 ) ;
	}

	DisplayBitMap() ;
	delay( 3000 ) ;

}

void DisplayBitMap()
{
	unsigned long data ;

	for ( uint8_t line = 0 ; line < 9 ; line++ )
	{
		data = BitMap[ 0 ][ line ] ;

		// this is where the bit-shifting happens to pull out
		// each LED from a row. If the bit is 1, then the LED
		// is turned on, otherwise it is turned off
		//
		for ( uint8_t led = 0 ; led < 14 ; ++led )
		{
			( data & ( 1 << led ) )
				? LedSign::Set( led, line, 1 )
				: LedSign::Set( led, line, 0 )
				;
		}
	}

	return ;
}
