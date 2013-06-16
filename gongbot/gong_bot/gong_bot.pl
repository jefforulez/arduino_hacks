#!/usr/bin/env perl

use strict ; 

use GongBot ;

MAIN:
{
	usage() if ( ! $ARGV[3] ) ;
	
	my $channel = $ARGV[4] || '#gongbot' ;
	
	print STDERR "starting GongBot\n" ;
	print STDERR "\t server: $ARGV[0]\n" ;
	print STDERR "\t port: $ARGV[1]\n" ;
	print STDERR "\t ssl: $ARGV[2]\n" ;
	print STDERR "\t data_filename: $ARGV[3]\n" ;
	print STDERR "\t channel: $channel\n" ;

	my $gongbot = GongBot->new( 
		server   => $ARGV[0],
		port     => $ARGV[1],
		ssl      => $ARGV[2],
		channels => [ $channel ],
		nick     => 'gongbot', 
		#
		_gongbot  => { 
			data_filename => $ARGV[3], 
		},
	) ;

	$gongbot->run() ;
	
}

sub usage
{
	print "gong_bot.pl <server> <port> <ssl> <data_filename> <channel>\n" ;
	exit 1 ;
}

exit ;

__DATA__

