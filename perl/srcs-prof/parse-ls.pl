#!/usr/bin/perl

use strict;
use warnings;
use utf8;

binmode(STDOUT,':utf8');




foreach my $fichier (@fichiers) {

	chop $fichier;

	print "$fichier\n";

	open(IN,"abu-cnam/$fichier");
	binmode(IN,':utf8');

	while (my $ligne = <IN>) {

        	chop $ligne;
		print "$ligne\n";

	}

	close(IN);


}