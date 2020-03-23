#!/usr/bin/perl

use strict;
use warnings;
use utf8;

binmode(STDOUT,':utf8');

open(IN,'tree-tagger-french lequipe/01.txt |');
binmode(IN,':utf8');

while (my $ligne = <IN>) {

	chop $ligne;

	my ($mot,$categorie,$lemme) = split(/\s+/,$ligne);

        if ($categorie !~ /^(DET|PRP|PUN|SENT)/) {
		print "$lemme\n";
	}

}

close(IN);