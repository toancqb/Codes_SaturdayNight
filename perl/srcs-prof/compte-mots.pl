#!/usr/bin/perl

use strict;
use warnings;
use utf8;

binmode(STDOUT,':utf8'); # utf8 pour la sortie standard

# lecture de la stop-list

my %stop = ();
open(IN,'stop.txt');
binmode(IN,':utf8');
while (my $mot = <IN>) {
	chop $mot;
	$stop{$mot} = 1;
}
close(IN);


# parcours du corpus

open(IN,'corpus-cv.txt');
binmode(IN,':utf8');

# tableau associatif pour stocker les mots
my %compteurs = ();

while (my $ligne = <IN>) {

    chop $ligne; # on enlève le passage à la ligne

    if ($ligne =~ /^[^{]/) {

        my $ligne = "\L$ligne";

        # sauvetage des expressions
        $ligne =~ s/mise en place/miseXenXplace/g;
        $ligne =~ s/gestion de projets?/gestionXdeXprojet/g;

        my @mots = split(/[\W\d]+/,$ligne);
        foreach my $mot (@mots) {
            if (($mot ne '') && (!exists($stop{$mot}))){
                # on crée une case étiquetée par le $mot
                # et au contenu quelconque
                # sans cette ligne le tableau reste vide
                # $compteurs{$mot} = 1;

                if (exists($compteurs{$mot})) {
                    $compteurs{$mot} = $compteurs{$mot}+1;
                } else {
                    $compteurs{$mot} = 1;
                }
            }
        }
    }
}

# affichage du vocabulaire par ordre alphabétique
#use locale;
#foreach my $mot (sort keys %compteurs) {
#    print "$mot\n";
#}

# affichage mots et compteurs
foreach my $mot (sort { $compteurs{$a} <=> $compteurs{$b} } keys %compteurs) {
    #if (!exists($stop{$mot})) {
    print $compteurs{$mot};
    $mot =~ s/X/ /g;
    print " $mot\n";
    #}
}


