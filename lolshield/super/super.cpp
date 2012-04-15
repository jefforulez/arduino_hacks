
//
// supercalifragilisticexpialidocious
//
// scroll supercalifragilisticexpialidocious across an lol shield
//
// author: @jefforulez
//

//
// based on lol shield library sample code
// http://code.google.com/p/lolshield/
//

#include "super.h"

void setup()
{
	LedSign::Init() ;
}

void loop()
{
	char* a = "supercalifragilisticexpialidocious  " ;
	Myfont::Banner( strlen( a ), (unsigned char*)( a ) ) ;
}
