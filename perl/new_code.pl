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
my @tab_fs = ();
my @tab_ms = ();
my @tab_1er = ();
my @tab_3eme = ();
my @tab_adj = ();
while (my $ligne = <INDICO>) {
		chop $ligne;
    $numligne = $numligne+1;
		if ($ligne =~ /N fs/) { push(@tab_fs, $ligne);}
		if ($ligne =~ /N ms/) { push(@tab_ms, $ligne);}
		if ($ligne =~ m/1er/) { push(@tab_1er, $ligne);}
		if ($ligne =~ m/3ème/) { push(@tab_3eme, $ligne);}
		if ($ligne =~ m/ADJ/) { push(@tab_adj, $ligne);}
}

print_tab("===feminin===", @tab_fs);
print_tab("===masculin===", @tab_ms);
print_tab("===1er groupe===", @tab_1er);
print_tab("===3eme groupe===", @tab_3eme);
print_tab("===adj===", @tab_adj);

close(INDICO);
