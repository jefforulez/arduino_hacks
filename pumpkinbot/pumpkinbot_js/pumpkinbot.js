
var irc = require( 'irc' ) ;
var net = require( 'net' ) ;
var rl  = require( 'readline' ) ;

//
// constants
//

const IRC_SERVER = 'irc.corp.pokkari.net' ;
const IRC_CHANNEL = '#pumpkinbot' ;

const IRC_HANDLE = 'pumpkinbot' ;
const IRC_REAL_NAME = 'pumpkinbot' ;
const IRC_DEBUG = true ;

const SERVER_PORT = 46641 ;

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
	}
) ;


irc.addListener(
	'pm',
	function ( from, message ) 
	{
		console.log( "[pm] from : " + from + ', message : ' + message ) ;
	}
) ;

irc.addListener(
	'error', 
	function ( message ) {
		console.log( "[error] " + message ) ;
	}
) ;



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
