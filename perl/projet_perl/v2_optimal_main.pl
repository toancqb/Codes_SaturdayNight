#!/usr/bin/perl

use strict;
use warnings;
use utf8;

use Term::ANSIColor;
binmode(STDOUT, ':utf8');

#  Datas #########################

#my @lst_mots = (
my @lst_verbe_mots = (
  ["avoir","ai","as","a","avons","avez","ont","avais",
  "avait","avions","aviez","avaient","eu","eus","eut",
  "eûmes","eûtes","eurent","aurai","auras","aura","aurons",
  "aurez","auront","aurais","aurait","aurions","auriez","auraient",
  "aie","aies","ait","ayons","ayez","aient","eusse","eusses"
  ,"eussions","eussiez","eussent"],
  ["être","suis","es","est","sommes","êtes","sont",
  "été","étais","était","étions","étiez","étaient",
  "fus","fus","fut","fûmes","fûtes","furent","serai",
  "seras","sera","serons","serez","seront","sois",
  "soit","soyons","soyez","soient","fusse","fusses",
  "fût","fussions","fussiez","fussent","serais",
  "serais","serait","serions","seriez","seraient",
  "étant"]
);

my @lst_color_mots = (
#my @lst_mots = (
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

#my @lst_noms_mots = (
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
	chop $mot;
	$dico{$mot} = 1;
}
close(INDICO);
##                              ##
##################################
##                              ##
my %mots_plus_utilises;         ##
my $nombre_mots = 0;            ##
my $nombre_mots_utilises = 0;   ##
##                              ##
##################################
##                              ##
my %mots_plus_utilises2;        ##
my $nombre_mots2 = 0;           ##
my $nombre_mots_utilises2 = 0;  ##
##                              ##
##################################

sub process {
  my $word = "";
  if ($_[0] eq "-" || $_[0] eq "!" || $_[0] eq "?"
    || $_[0] eq "—"|| $_[0] eq ":" || $_[0] eq "»"
    || $_[0] eq "«"|| $_[0] eq ";") {
    return "";
  }
  $word = lc($_[0]);
  my $n = index($word, "\'");
  $word = substr $word, $n + 1;
  $word =~ s/[\.\,\(\)\…\»]//g;
  return $word;
}

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

sub manipuler_word2 {
  my $word = $_[0];
  $word = is_mot_plus_utilise($word);
  if ($word ne "") {
    $mots_plus_utilises2{$word} += 1;
    $nombre_mots_utilises2 += 1;
  }
}

sub print_color {
  print color($_[0]), $_[1], color('reset');
}

sub cherche_mot {
  my $mot = $_[0];
  my $fichier = $_[1];
  my $numligne = 0;

  open(IN, $fichier);
  binmode(IN,':utf8');

  print color('bold blue'),"[$fichier]: \n",color('reset');

  while (my $ligne = <IN>) {
    chop $ligne;
    $numligne += 1;

    if ($ligne =~ /^(.*)($mot\w*)(.*)$/) {

      my $gauche = $1;
      my $motif  = $2;
      my $droite = $3;

      if (length($gauche)>30) {
        $gauche = substr($gauche,-30,30);
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
## Lire la premiere ouvre        ##

my $nombre_argv = $#ARGV + 1;
if ($nombre_argv > 0) {
  cherche_mot("$ARGV[0]", "stevenson/stevenson-fr-v2.txt");
  for (my $file=1; $file <=22; $file=$file+1) {

    if ($file < 10) {
      $file = "0$file";
    }
    cherche_mot("$ARGV[0]", "harry-potter/part-$file.txt");

  }
} else { ## START ELSE
for (my $file=1; $file <=22; $file=$file+1) {

  if ($file < 10) {
    $file = "0$file";
  }
  open(IN, "harry-potter/part-$file.txt");
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
}
##                               ##
###################################
## Lire la deuxieme ouvre        ##

open(IN, "stevenson/stevenson-fr-v2.txt");
binmode(IN,':utf8');

while (my $ligne = <IN>) {

    chop $ligne; # on enlève le passage à la ligne

    my @splited_word = split(/[\W\d]+/,"\L$ligne");
    foreach my $word (@splited_word) {
      if ($word ne '') {
        if (exists($dico{$word})) {
          manipuler_word2($word);
          $nombre_mots2 = $nombre_mots2 + 1;
        }
      }
    }
}
close(IN);
##                               ##
###################################
## Print Resultats               ##
my %resultats;

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

@keys = keys %mots_plus_utilises2;
$size = @keys;
##
print color('bold black on_green'), "- Le nombre totale des mots:               ", color('reset');
print color('bold red on_yellow');
printf("%10i\n", $nombre_mots2); print color('reset');

print color('bold black on_green'), "- Le nombre totale des mots plus utilises: ", color('reset');
print color('bold red on_yellow');
printf("%10i\n",$nombre_mots_utilises2); print color('reset');

$percent = $nombre_mots_utilises2*100/$nombre_mots2;

print color('bold black on_green'), "- Use of the 50 most common noun words:    ", color('reset');
print color('bold red on_yellow');
printf("%9.2f%%\n", $percent); print color('reset');

print color('bold black on_green'), "- Le nombre des mots plus utilises:        ", color('reset');
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
  print color('on_white'), "                          \n", color('reset');
  if ($top >= 20) {
    last;
  }
  $top += 1;
}
} ## Fin ELSE
