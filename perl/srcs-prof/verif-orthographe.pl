#!/usr/bin/perl

use strict;
use warnings;
use utf8;

binmode(STDOUT,':utf8'); # utf8 pour la sortie standard


# lecture du dictionnaire

my %dico = ();
open(INDICO,'dictionnaire-2020.txt');
binmode(INDICO,':utf8');
while (my $mot = <INDICO>) {
	chop $mot;
	$dico{$mot} = 1;
}
close(INDICO);



# parcours du corpus

open(IN,'corpus-cv.txt');
binmode(IN,':utf8');

while (my $ligne = <IN>) {

    chop $ligne; # on enlève le passage à la ligne

    # on sélection les lignes de texte libre
    #if (($ligne =~ /^{PERSONNE}.*$/)
    # || ($ligne =~ /^{EXPERIENCE}/)) {
    #    # on ne fait rien
    #} else {
    #    print "$ligne\n";
    #}

    if ($ligne =~ /^[^{]/) {
        #print "$ligne\n";
        #my @mots = split(/[ ,;.‣]+/,$ligne);
        # découpage après normalisation  
        my @mots = split(/[\W\d]+/,"\L$ligne");
        foreach my $mot (@mots) {
            if ($mot ne '') {
                if (!exists($dico{$mot})) {
                    print "$mot\n";
                }
            }
        }
    }

}





