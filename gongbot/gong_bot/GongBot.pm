#!/usr/bin/env perl

use strict ;

package GongBot ;

use base qw( Bot::BasicBot ) ;

use Data::Dumper ;

use IO::File ;
use IO::Select ;

sub init
{
	my ( $self ) = @_ ;

	print STDERR "GongBot::init()\n" ;
	print Dumper( $self ), "\n" ;
	
	return 1 ;
}

sub connected 
{
	my ( $self ) = @_ ;

	print STDERR "GongBot::connected()\n" ;
	
	my $filename = $self->{ '_gongbot' }{ 'data_filename' } ;

	my $fh = IO::File->new( $filename ) ;

	if ( ! $fh ) {
		print STDERR "unable to open data file, filename : $filename\n" ;
		$self->shutdown( '' ) ;
	}

	my $io_select = IO::Select->new( $fh ) ;

	$self->{ '_gongbot' }{ 'io_select' } = $io_select ;

	return ;
}

=pod
sub said 
{
	my ( $self, $msg ) = @_ ;
	print STDERR Dumper( $msg ), "\n" ;
	return ;
}
=cut

sub tick
{
	my ( $self ) = @_ ;

	my $io_select = $self->{ '_gongbot' }{ 'io_select' } ;
	
	while ( my @ready = $io_select->can_read(0) ) 
	{
		foreach my $fh ( @ready ) 
		{
			my $line = <$fh> ;
			chomp $line ;

			if ( $line =~ m/^\s*(\d+)\s*$/ )
			{
				my $val = $1 ;
			
				if ( $val >= 5 ) 
				{
					print STDERR "line : $line\n" ;
					
					$self->say(
						channel => ( $self->channels )[0],
						body    => ( $val >= 10 ) ? "*** GONG ***" : "... gong ..."
					) ;
				}
				
			}
			else 
			{
				print STDERR "unexpected data, line : '$line'\n" ;
			} 
		}
	}

	return 2 ;
}


1; 

__END__

