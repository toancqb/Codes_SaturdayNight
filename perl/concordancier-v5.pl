#!/usr/bin/perl

use strict;
use warnings;
use utf8;

use Term::ANSIColor;
# https://perldoc.perl.org/Term/ANSIColor.html

binmode(STDOUT,':utf8');

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

        if ($ligne =~ /^(.*)(passe\w*)(.*)$/) {

            my $gauche = $1;
            my $motif  = $2;
            my $droite = $3;

            if (length($gauche)>30) {
                $gauche = substr($gauche,-30,30);
            }

            # vvv ajouts par rapport à la version 2 vvv
            my @mots = split(/\W+/,$droite);
            my $droite = '';
            my $maxmots = 5;
            if (scalar(@mots)<$maxmots) {
                $maxmots = scalar(@mots);
            }
            for (my $i=0 ; $i<$maxmots ; $i=$i+1) {
                $droite = $droite.$mots[$i].' ';
            }
            # ^^^ ajouts par rapport à la version 2 ^^

            # 
            print color('bold blue'),"$fichier: ",color('reset');
            print color('bright_magenta');
            printf("%3i: ",$numligne);
            print color('reset');

            print color('bold white');
            printf("%30s",$gauche);
            print color('reset');

            print color('green on_white');
            printf("%-10s",$motif);
            print color('reset');

            print color('bold white'),$droite,color('reset');
            print "\n";

        }

    }

    close(IN);
}

