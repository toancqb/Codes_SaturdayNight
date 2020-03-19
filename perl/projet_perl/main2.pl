#!/usr/bin/perl

use strict;
use warnings;
use utf8;
use Term::ANSIColor;

my $nombre_mots = 124866;
my $nombre_mots_utilises = 1635;
my $size = 44;

sub print_color {
  print color($_[0]), $_[1], color('reset');
}

#print color('bold black on_green'), "- Le nombre totale des mots:               ", color('reset');
print_color('bold black on_green', "- Le nombre totale des mots:               ");
print color('bold red on_white');
printf("%10i\n", $nombre_mots); print color('reset');

print color('bold black on_green'), "- Le nombre totale des mots plus utilises: ", color('reset');
print color('bold red on_white');
printf("%10i\n",$nombre_mots_utilises); print color('reset');

my $percent = $nombre_mots_utilises*100/$nombre_mots;

print color('bold black on_green'), "- Use of the 50 most common noun words:    ", color('reset');
print color('bold red on_white');
printf("%9.2f%%\n", $percent); print color('reset');

print color('bold black on_green'), "- Le nombre des mots plus utilises:        ", color('reset');
print color('bold red on_white');
printf("%10i\n",$size); print color('reset');
