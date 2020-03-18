#!/usr/bin/perl

use strict;
use warnings;
use utf8;

binmode(STDOUT,':utf8');

my %apparitions = ();

for (my $fichier=1 ; $fichier<=10 ; $fichier=$fichier+1) {

    if ($fichier < 10) {
        $fichier = "0$fichier";
    }

    open(IN,"lequipe/$fichier.txt");
    binmode(IN,':utf8');

    my $numligne = 0;

    while (my $ligne = <IN>) {

        chop $ligne;
        $numligne = $numligne+1;

        if ($ligne =~ /passe/) {
            $ligne =~ s/(passe\w*)/😃 $1 😃/g;
	    my $forme     = $1;
            my $affichage = "$fichier: $numligne: $ligne\n";
	    if (exists($apparitions{$forme})) {
		my $reftableau = $apparitions{$forme};
		push(@$reftableau,$affichage);
	    } else { # première apparition de la forme
	    	$apparitions{$forme} = [ $affichage ]; # on associe à la forme l'adresse d'un tableau
	    }
        }
    }

    close(IN);
}


foreach my $forme (keys %apparitions) {
	print "\U$forme\n";
	# récupération du tableau à partir de son adresse (stockée dans une case de tableau associatif)
	my @phrases = @{ $apparitions{$forme} };
	foreach my $phrase (@phrases) {
		print $phrase;
	}
	print "\n";
}






