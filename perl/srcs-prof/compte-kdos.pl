#!/usr/bin/perl
# interpréteur

use strict;              # utiliser perl en mode strict (= comme en algo)
use warnings;            # avoir des signalements de problèmes éventuels
use utf8;                # utiliser des accents dans le programme

binmode(STDOUT,':utf8'); # utf8 pour la sortie standard

my %compteur = ();

open(IN,'kdos.txt');
binmode(IN,':utf8');
while (my $ligne = <IN>) {
    chop $ligne;
    if ($ligne =~ /(\d+ ans)/) {

        my $age = $1;
        #print "$age\n";

        if (exists($compteur{$age})) {
            $compteur{$age} = $compteur{$age} + 1;
        } else {
            $compteur{$age} = 1;
        }

    }

}
close(IN);


foreach my $age (sort {$compteur{$b} <=> $compteur{$a} } (keys %compteur)) {
    print "enfants de $age : $compteur{$age} jouets.\n";
}





