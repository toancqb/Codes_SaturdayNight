#!/usr/bin/perl

use strict;
use warnings;
use utf8;

use Term::ANSIColor;
binmode(STDOUT, ':utf8');

#  Datas #########################

# my @lst_mots = (
my @lst_verbe_mots = (
["aller","vais","vas","va","allons","allez","vont","allé","allés","allés",
"allés","allais","allait","allions","alliez","allaient","allai","allas",
"alla","allâmes","allâtes","allèrent","irai","iras","ira","irons","irez",
"iront","allasse","allasses","allât","allassions","allassiez","allassent",
"allant"],
["faire","fais","fait","faisons","faites","font","faisais","faisait","faisions",
"faisiez","faisaient","fis","fit","fîmes","fîtes","firent","ferai","feras",
"fera","ferons","ferez","feront","faisant","fasse","fasses","fassions","fassiez",
"fassent","fisse","fisses","fît","fissions","fissiez","fissent"]
);

my @lst_color_mots = (
# my @lst_mots = (
 ["blanc","blancs","blanche","blanches"],
 ["noir","noirs","noire","noires"],
 ["rouge","rouges"],
 ["vert","verts","verte","vertes"],
 ["orange","oranges"],
 ["marron","marron"],
 ["bleu","bleus","bleue","bleues"],
 ["violet","violets","violette","violettes"],
 ["gris","grise","grises"],
 ["rose","roses"],
 ["jaune","jaunes"],
);

# my @lst_noms_mots = (
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
#################################
##                             ##
my %dico = ();
open(INDICO,'dictionnaire-2020.txt');
binmode(INDICO,':utf8');
while (my $mot = <INDICO>) {
	chop $mot; # on enlève le passage à la ligne
	$dico{$mot} = 1;
}
close(INDICO);
my %dico_stop = ();
open(INDICO,'stop.txt');
binmode(INDICO,':utf8');
while (my $mot = <INDICO>) {
	chop $mot; # on enlève le passage à la ligne
	$dico_stop{$mot} = 1;
}
close(INDICO);
##                              ##
##################################
##                              ##
my $title1 = "            <~HARRY POTTER~>                                    \n";
my %mots_plus_utilises;         ##
my $nombre_mots = 0;            ##
my $nombre_mots_utilises = 0;   ##
##                              ##
##################################
##                              ##
my $title2 = "             <~STEVENSON~>                                      \n";

my %mots_plus_utilises2;        ##
my $nombre_mots2 = 0;           ##
my $nombre_mots_utilises2 = 0;  ##
##                              ##
##################################

sub is_mot_dans_lst_mots {
  my $mot = $_[0]; # mot on a besoin de verifier

  for (my $i = 0 ; $i < @lst_mots ; $i++) {
    for (my $j = 0 ; $j < @{$lst_mots[$i]} ; $j++ ) {
        if ($mot eq $lst_mots[$i][$j]) { # si le mot est egal a un des mots dans @lst_mots[$i]
          return $lst_mots[$i][0]; # retourner le valeur de premier element
        }                          # Pour ca, on peut compter blanc, blancs, blanche, blanches
                                   # comme un mot unique
    }
  }
  return "";
}

sub manipuler_word {
  my $word = $_[0];
  $word = is_mot_dans_lst_mots($word); # verifier si $word est dans @lst_mots
  if ($word ne "") {                   # et $word = le premier valeur dans @lst_mots[$i]
    $mots_plus_utilises{$word} += 1;   # enregistrer $word dans dictionnaire %mots_plus_utilises
    $nombre_mots_utilises += 1;        # compter $nombre_mots_utilises += 1
  }
}

sub manipuler_word2 {
  my $word = $_[0];
  $word = is_mot_dans_lst_mots($word); # verifier si $word est dans @lst_mots
  if ($word ne "") {                   # et $word = le premier valeur dans @lst_mots[$i]
    $mots_plus_utilises2{$word} += 1;  # enregistrer $word dans dictionnaire %mots_plus_utilises2
    $nombre_mots_utilises2 += 1;       # compter $nombre_mots_utilises2 += 1
  }
}

sub print_color {
  print color($_[0]), $_[1], color('reset'); # shortcut d'utilisation de print color
}

sub cherche_mot { # C'est la fonction de professeur Fabien-Torre
  my $mot = $_[0];
  my $fichier = $_[1];
  my $numligne = 0;

  open(IN, $fichier);
  binmode(IN,':utf8');

  print color('bold blue'),"[$fichier]: \n",color('reset');

  while (my $ligne = <IN>) {
    chop $ligne; # on enlève le passage à la ligne
    $numligne += 1; # on compte $numligne += 1

    if ($ligne =~ /^(.*)($mot\w*)(.*)$/) {
# Cherche tous les lignes qui contient $mot*
      my $gauche = $1; # de la gauche de $mot*
      my $motif  = $2;
      my $droite = $3; 

      if (length($gauche)>30) {
        $gauche = substr($gauche,-30,30); # on coupe $gauche si len($gauche)>30
      }

      # vvv ajouts par rapport à la version 2 vvv
      my @mots = split(/\W+/,$droite);
      $droite = '';
      my $maxmots = 5;
      if (scalar(@mots)<$maxmots) {
        $maxmots = scalar(@mots);
      }
      for (my $i=0 ; $i<$maxmots ; $i=$i+1) {
        $droite = $droite.$mots[$i].' ';
      }
      # ^^^ ajouts par rapport à la version 2 ^^
      #

      print color('bright_magenta');
      printf("%5i: ",$numligne);
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

##                               ##
###################################
## La Fonction Main commence     ##

my $nombre_argv = $#ARGV + 1;
if ($nombre_argv > 0) {
  cherche_mot("$ARGV[0]", "stevenson/stevenson-fr-v2.txt");
  for (my $file=1; $file <=22; $file=$file+1) {

    if ($file < 10) {
      $file = "0$file";
    }
    cherche_mot("$ARGV[0]", "harry-potter/part-$file.txt");

  }
} else { ## ELSE Commence

##                               ##
###################################
## Lire la premiere ouvre        ##

for (my $file=1; $file <=22; $file=$file+1) {

  if ($file < 10) {
    $file = "0$file";
  }
  open(IN, "harry-potter/part-$file.txt");
  binmode(IN,':utf8');

  while (my $ligne = <IN>) {

      chop $ligne; # on enlève le passage à la ligne

      my @splited_word = split(/[\W\d]+/,"\L$ligne"); # Split la ligne pour des mots
      foreach my $word (@splited_word) { # Pour chaque mot
        if ($word ne '') {
          if (!exists($dico_stop{$word}) and exists($dico{$word})) {
            manipuler_word($word); # On ne traite que les mots dans le dictionnaire %dico
          }                        # sauf que les mots dans le dictionnaire %dico_stop
          $nombre_mots = $nombre_mots + 1;
        }
      }
  }
  close(IN);
}
##                               ##
###################################
## Lire la deuxieme ouvre        ##

open(IN, "stevenson/stevenson-fr-v2.txt");
binmode(IN,':utf8');

while (my $ligne = <IN>) {

    chop $ligne; # on enlève le passage à la ligne

    my @splited_word = split(/[\W\d]+/,"\L$ligne"); # Split la ligne pour des mots
    foreach my $word (@splited_word) { # Pour chaque mot
      if ($word ne '') {
        if (!exists($dico_stop{$word}) and exists($dico{$word})) {
          manipuler_word2($word); # On ne traite que les mots dans le dictionnaire %dico
        }                         # sauf que les mots dans le dictionnaire %dico_stop
        $nombre_mots2 = $nombre_mots2 + 1;
      }
    }
}
close(IN);
##                               ##
###################################
## Print Resultats               ##

my @keys = keys %mots_plus_utilises;
my $size = @keys;
##
print_color('bold red on_blue', $title1);
##
print color('bold black on_green'), "- Nombre total des mots du texte:                     ", color('reset');
print color('bold red on_yellow');
printf("%10i\n", $nombre_mots); print color('reset');

print color('bold black on_green'), "- Mots faisant partie de la liste des 50 plus utilise:", color('reset');
print color('bold red on_yellow');
printf("%10i\n",$nombre_mots_utilises); print color('reset');

my $percent = $nombre_mots_utilises*100/$nombre_mots;

print color('bold black on_green'), "- Pourcentage des 50 mots les plus communs:           ", color('reset');
print color('bold red on_yellow');
printf("%9.2f%%\n", $percent); print color('reset');

print color('bold black on_green'), "- Nombre de ces mots sans repetition:                 ", color('reset');
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
  print color('on_white'), "                                     \n", color('reset');
  if ($top >= 15) {
    last;
  }
  $top += 1;
}

@keys = keys %mots_plus_utilises2;
$size = @keys;
##
print_color('bold red on_blue', $title2);
##
print color('bold black on_green'), "- Nombre total des mots du texte:                     ", color('reset');
print color('bold red on_yellow');
printf("%10i\n", $nombre_mots2); print color('reset');

print color('bold black on_green'), "- Mots faisant partie de la liste des 50 plus utilise:", color('reset');
print color('bold red on_yellow');
printf("%10i\n",$nombre_mots_utilises2); print color('reset');

$percent = $nombre_mots_utilises2*100/$nombre_mots2;

print color('bold black on_green'), "- Pourcentage des 50 mots les plus communs:           ", color('reset');
print color('bold red on_yellow');
printf("%9.2f%%\n", $percent); print color('reset');

print color('bold black on_green'), "- Nombre de ces mots sans repetition:                 ", color('reset');
print color('bold red on_yellow');
printf("%10i\n",$size); print color('reset');
##
$top = 1;
foreach my $k (reverse sort {$mots_plus_utilises2{$a} <=> $mots_plus_utilises2{$b}} keys %mots_plus_utilises2) {
  #print "-=[$k]=- : $mots_plus_utilises2{$k}\n";
  print_color('bold black on_white', "-=[");
  print color('bold red on_yellow');
  printf("%-10s", $k); print color('reset');
  print_color('bold black on_white', "]=- : ");
  print color('bold black on_cyan');
  printf("%8i", $mots_plus_utilises2{$k}); print color('reset');
  print color('on_white'), "                                     \n", color('reset');
  if ($top >= 15) {
    last;
  }
  $top += 1;
}
} ## Fin ELSE
