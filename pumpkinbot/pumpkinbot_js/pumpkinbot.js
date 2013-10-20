
var irc = require( 'irc' ) ;
var net = require( 'net' ) ;
var rl  = require( 'readline' ) ;

//
// constants
//

const IRC_SERVER = 'irc.example.com' ;
const IRC_CHANNEL = '#pumpkinbot' ;

const IRC_HANDLE = 'pumpkinbot' ;
const IRC_REAL_NAME = 'pumpkinbot' ;
const IRC_DEBUG = true ;

const SERVER_PORT = 46641 ;

//
// arduino IP address
//

const ARDUINO_PORT = 14664 ;

var arduino_ip = "127.0.0.1" ;

//
// configure the irc client
//

var irc = new irc.Client(
	IRC_SERVER,
	IRC_HANDLE, 
	{
		channels : [ IRC_CHANNEL ],
		realName : IRC_REAL_NAME,
		//
		showErrors : true,
		debug : IRC_DEBUG,
	}
) ;

irc.addListener(
	'registered', 
	function ( message ) {
		console.log( "[registered] " ) ;
		console.log( message ) ;
	}
) ;

irc.addListener(
	'names', 
	function ( channel, nicks ) {
		console.log( "[names] channel : " + channel + ", nicks : " + nicks ) ;
	}
) ;


irc.addListener(
	'message', 
	function ( from, to, message ) {
		console.log( "[message] from : " + from + ', to : ' + to + ', message : ' + message ) ;
		
		if ( from == "plusplusbot" )
		{
			if (
				message.match( /^(owie|daaa|awww|denied|ya dun)/ )
			)
			{
				sendCommandToArduino( 'minusminus' ) ;			
			}
			else if (
				message.match( /^(well played|suh-weet|fist|w00t|wOOt)/ )			
			)
			{
				sendCommandToArduino( 'plusplus' ) ;
			}
			else
			{
				sendCommandToArduino( 'blink' ) ;
			}
		}
		
	}
) ;


irc.addListener(
	'pm',
	function ( from, message ) 
	{
		console.log( "[pm] from : " + from + ', message : ' + message ) ;
		
		if ( from.match( /^jeffo/ ) )
		{
			sendCommandToArduino( message.trim() ) ;
		}
	}
) ;

irc.addListener(
	'error', 
	function ( message ) {
		console.log( "[error] " + message ) ;
	}
) ;


//
// send a command to the arduino
//

function sendCommandToArduino ( command )
{
	try
	{
		var client = net.connect(
			{ port : ARDUINO_PORT, host : arduino_ip },
			function() {
				console.log( 'client connected' ) ;
				client.write( command + '\r\n' ) ;
				console.log( 'client sent command: ' + command ) ;
				client.end() ;
			}
		) ;
	}
	catch (e) {
		console( "sendCommandToArduino(), e : " + e ) ;
	}
}

//
// configure the server
//

var server = net.createServer(
	function ( socket ) 
	{
		var i = rl.createInterface( socket, socket ) ;
		i.on( 
			'line', 
			function ( line ) { 
				console.log( "[server:line] " + line ) ;
				
				// set target ip address
				arduino_ip = line.trim ;
			} 
		) ;
	}
) ;

server.listen(
	SERVER_PORT, 
	function () {
		console.log( '[server] bound' ) ;
	}
) ;

//
//

console.log( 'pumpkinbot.js started' ) ;
