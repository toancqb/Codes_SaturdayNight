#!/usr/bin/perl

use strict;
use warnings;
use utf8;

use Term::ANSIColor;

binmode(STDOUT,':utf8'); # utf8 pour la sortie standard


my @lst_mots = (
	["maison","maisons"],
	["tête","têtes"],
	["ville","villes"],
	["temps","temps"],
	["porte","portes"],
	["pays"],
	["route","routes"],
	["fleur","fleurs"],
	["raison","raisons"],
	["homme","hommes"],
	["cœur"],
	["femme","femmes"],
	["dieu","dieux"],
	["monde","mondes"],
	["voiture","voitures"],
	["jour","jours"],
	["temps"],
	["monsieur","messieurs"],
	["personne","personnes"],
	["fois"],
	["chambre","chambres"],
	["lit","lits"],
	["adresse","adresses"],
	["avion","avions"],
	["chemin","chemins"],
	["école","écoles"],
	["village","villages"],
	["voyage","voyages"],
	["arbre","arbres"],
	["mer","mers"],
	["eau","eaux"],
	["journal","journaux"],
	["détail","détails"],
	["hôpital","hôpitaux"],
	["portail","portails"],
	["berceau","berceaux"],
	["souris","souris"],
	["oiseau","oiseaux"],
	["nez"],
	["feu","feux"],
	["tuyau","tuyaux"],
	["cheval","chevaux"],
	["soldat","soldats"],
	["boîte","boîtes"],
	["cheveu","cheveux"],
	["chaussure","chaussures"],
	["balle","balles"],
	["gaz"],
	["oeuf","oeufs"],
	["légume","légumes"],
);

##################################
##                              ##
my %mots_plus_utilises;         ##
my $nombre_mots = 0;            ##
my $nombre_mots_utilises = 0;   ##
##                              ##
##################################

sub is_mot_plus_utilise {
  my $mot = $_[0];

  for (my $i = 0 ; $i < @lst_mots ; $i++) {
    for (my $j = 0 ; $j < @{$lst_mots[$i]} ; $j++ ) {
        if ($mot eq $lst_mots[$i][$j]) {
          return $lst_mots[$i][0];
        }
    }
  }
  return "";
}

sub manipuler_word {
  my $word = $_[0];
  $word = is_mot_plus_utilise($word);
  if ($word ne "") {
    $mots_plus_utilises{$word} += 1;
    $nombre_mots_utilises += 1;
  }
}

sub print_color {
  print color($_[0]), $_[1], color('reset');
}

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

open(IN,"stevenson/stevenson-fr-v2.txt");
binmode(IN,':utf8');

while (my $ligne = <IN>) {

    chop $ligne; # on enlève le passage à la ligne

    my @splited_word = split(/[\W\d]+/,"\L$ligne");
    foreach my $word (@splited_word) {
      if ($word ne '') {
        if (exists($dico{$word})) {
          manipuler_word($word);
          $nombre_mots = $nombre_mots + 1;
        }
      }
    }
}

close(IN);


my @keys = keys %mots_plus_utilises;
my $size = @keys;
##
print color('bold black on_green'), "- Le nombre totale des mots:               ", color('reset');
print color('bold red on_yellow');
printf("%10i\n", $nombre_mots); print color('reset');

print color('bold black on_green'), "- Le nombre totale des mots plus utilises: ", color('reset');
print color('bold red on_yellow');
printf("%10i\n",$nombre_mots_utilises); print color('reset');

my $percent = $nombre_mots_utilises*100/$nombre_mots;

print color('bold black on_green'), "- Use of the 50 most common noun words:    ", color('reset');
print color('bold red on_yellow');
printf("%9.2f%%\n", $percent); print color('reset');

print color('bold black on_green'), "- Le nombre des mots plus utilises:        ", color('reset');
print color('bold red on_yellow');
printf("%10i\n",$size); print color('reset');
##
my $top = 1;
foreach my $k (reverse sort {$mots_plus_utilises{$a} <=> $mots_plus_utilises{$b}} keys %mots_plus_utilises) {
  #print "-=[$k]=- : $mots_plus_utilises{$k}\n";
  print_color('bold black on_white', "-=[");
  print color('bold red on_yellow');
  printf("%-10s", $k); print color('reset');
  print_color('bold black on_white', "]=- : ");
  print color('bold black on_cyan');
  printf("%8i", $mots_plus_utilises{$k}); print color('reset');
  print color('on_white'), "                          \n", color('reset');
  if ($top >= 20) {
    last;
  }
  $top += 1;
}
