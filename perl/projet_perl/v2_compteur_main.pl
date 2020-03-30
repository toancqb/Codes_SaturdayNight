#!/usr/bin/perl

use strict;
use warnings;
use utf8;

use Term::ANSIColor;
binmode(STDOUT, ':utf8');

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
my %dico_stop = ();
open(INDICO,'stop.txt');
binmode(INDICO,':utf8');
while (my $mot = <INDICO>) {
	chop $mot;
	$dico_stop{$mot} = 1;
}
close(INDICO);
##                              ##
##################################
##                              ##
my $title1 = "         <~HARRY POTTER~>                               \n";
my %dmots;         ##
my $nombre_mots = 0;            ##
my $nombre_dmots = 0;   ##
##                              ##
##################################
##                              ##
my $title2 = "           <~STEVENSON~>                                \n";
my %dmots2;        ##
my $nombre_mots2 = 0;           ##
my $nombre_dmots2 = 0;  ##
##                              ##
##################################

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
    chop $ligne; # on enlève le passage à la ligne
    $numligne += 1; # on compte $numligne += 1

    if ($ligne =~ /^(.*)($mot\w*)(.*)$/) {
# Cherche tous les lignes qui contient $mot*
      my $gauche = $1; # de la gauche de $mot*
      my $motif  = $2;
      my $droite = $3; # de la droite de $mot*

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

      my @splited_words = split(/[\W\d]+/,"\L$ligne");
      foreach my $word (@splited_words) {
        if ($word ne '') {
          if (!exists($dico_stop{$word}) && exists($dico{$word})) {
            $dmots{$word} += 1;
            $nombre_dmots += 1;

          }
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

    my @splited_words = split(/[\W\d]+/,"\L$ligne");
    foreach my $word (@splited_words) {
      if ($word ne '') {
        if (!exists($dico_stop{$word}) && exists($dico{$word})) {
          $dmots2{$word} += 1;
          $nombre_dmots2 += 1;

        }
        $nombre_mots2 = $nombre_mots2 + 1;
      }
    }
}
close(IN);
##                               ##
###################################
## Print Resultats               ##

my @keys = keys %dmots;
my $size = @keys;
##
print_color('bold red on_blue', $title1);
##
print_color('bold black on_green', "- Nombre total des mots du texte:             ");
print color('bold red on_yellow');
printf("%10i\n", $nombre_mots); print color('reset');

print_color('bold black on_green', "- Nombre total de mots differents:            ");
print color('bold red on_yellow');
printf("%10i\n",$nombre_dmots); print color('reset');

my $percent = $nombre_dmots*100/$nombre_mots;

print_color('bold black on_green', "- Pourcentage:                                ");
print color('bold red on_yellow');
printf("%9.2f%%\n", $percent); print color('reset');

print_color('bold black on_green', "- Le nombre des mots utilises:                ");
print color('bold red on_yellow');
printf("%10i\n",$size); print color('reset');
##
my $top = 1;
foreach my $k (reverse sort {$dmots{$a} <=> $dmots{$b}} keys %dmots) {
  #print "-=[$k]=- : $dmots{$k}\n";
  print_color('bold black on_white', "-=[");
  print color('bold red on_yellow');
  printf("%-10s", $k); print color('reset');
  print_color('bold black on_white', "]=- : ");
  print color('bold black on_cyan');
  printf("%8i", $dmots{$k}); print color('reset');
  print color('on_white'), "                             \n", color('reset');
  if ($top >= 15) {
    last;
  }
  $top += 1;
}

@keys = keys %dmots2;
$size = @keys;
##
print_color('bold red on_blue', $title2);
##
print_color('bold black on_green', "- Nombre total de mots:                       ");
print color('bold red on_yellow');
printf("%10i\n", $nombre_mots2); print color('reset');

print_color('bold black on_green', "- Nombre total de mots differents:            ");
print color('bold red on_yellow');
printf("%10i\n",$nombre_dmots2); print color('reset');

$percent = $nombre_dmots2*100/$nombre_mots2;

print_color('bold black on_green', "- Pourcentage:                                ");
print color('bold red on_yellow');
printf("%9.2f%%\n", $percent); print color('reset');

print_color('bold black on_green', "- Le nombre des mots utilises:                ");
print color('bold red on_yellow');
printf("%10i\n",$size); print color('reset');
##
$top = 1;
foreach my $k (reverse sort {$dmots2{$a} <=> $dmots2{$b}} keys %dmots2) {
  #print "-=[$k]=- : $dmots2{$k}\n";
  print_color('bold black on_white', "-=[");
  print color('bold red on_yellow');
  printf("%-10s", $k); print color('reset');
  print_color('bold black on_white', "]=- : ");
  print color('bold black on_cyan');
  printf("%8i", $dmots2{$k}); print color('reset');
  print color('on_white'), "                             \n", color('reset');
  if ($top >= 15) {
    last;
  }
  $top += 1;
}
} ## Fin ELSE
