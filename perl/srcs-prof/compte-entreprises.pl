#!/usr/bin/perl
# interpréteur

use strict;              # utiliser perl en mode strict (= comme en algo)
use warnings;            # avoir des signalements de problèmes éventuels
use utf8;                # utiliser des accents dans le programme

binmode(STDOUT,':utf8'); # utf8 pour la sortie standard




open(IN,'corpus-cv.txt');
binmode(IN,':utf8');

# création du tableau associatif vide
my %entreprises = ();

while (my $ligne = <IN>) {

   chop $ligne; # on enlève le passage à la ligne

   # on cible les lignes qui commencent par {EXPERIENCE}
   # et on récupère la suite
   if ($ligne =~ /^{EXPERIENCE}(.*)$/) {

#   if ($ligne =~ /^{EXPERIENCE}[^,]*,[^,]*,(.*),/) {
#      my $entreprise = $1;

      my $description = $1; # on nomme la partie extraite

      #my ($poste,$mission,$entreprise,@reste) = split(/,/,$description);

      # on découpe selon les virgules
      my @infos = split(/,/,$description);
      # et on récupère le 3e champ
      my $entreprise = $infos[2];

      #print "$entreprise\n";

      # on normalise le nom de l'entreprise : minuscules avec \L
      $entreprise = "\L$entreprise";

      # on crée ou on écrase la case associée à l'entreprise
      # dans le tableau associatif : on élimine les redondances
      # $entreprises{$entreprise} = 1;

      # on met à jour le compteur de l'entreprise
      if (exists($entreprises{$entreprise})) {
          $entreprises{$entreprise} = $entreprises{$entreprise} + 1;
      } else {
          $entreprises{$entreprise} = 1;
      }

   }

}
close(IN);

# affichage des entreprises par ordre alphabétique
#use locale; # pour un ordre alphabétique français
#foreach my $entreprise (sort keys %entreprises) {
#      print " $entreprise\n"; 
#}

# affichage des entreprises par ordre d'importance
foreach my $entreprise (sort {$entreprises{$a} <=> $entreprises{$b} } keys %entreprises) {
      print $entreprises{$entreprise}; # affichage du compteur
      print " $entreprise\n"; 
}





