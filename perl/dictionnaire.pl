#!/usr/bin/perl

use strict;
use warnings;
use utf8;
use Fcntl;

sub print_tab
{
	my $label = shift;
	my @args = @_;
	print("$label\n");
	foreach my $i (@args) {
		print("$i\n");
	}
}
### Read file
binmode(STDOUT,':utf8');
binmode(STDIN,':utf8');

open(INDICO,'perl.txt');
binmode(INDICO,':utf8');
###

my $numligne = 0;
my @tab = ();
while (my $ligne = <INDICO>) {
		chop $ligne;
    push(@tab, $ligne);
}


close(INDICO);
