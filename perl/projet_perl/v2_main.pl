#!/usr/bin/perl

use strict;
use warnings;
use utf8;

binmode(STDOUT, ':utf8');

# define
# NFILE

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
#  Lires #########################

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

my %mots_plus_utilises;
#my @splited_word;
my $nombre_mots = 0;
my $nombre_mots_utilises = 0;

sub print_lst_mots {
  foreach my $tab (@_) {
    foreach my $m ($tab) {
      print "-[$m]-";
    }
    print "\n";
  }
}

sub is_mot_plus_utilise {
  my $mot = $_[0];
  my $str_tmp = "";
  for (my $i = 0 ; $i < @lst_mots ; $i++) {
    for (my $j = 0 ; $j < @{$lst_mots[$i]} ; $j++ ) {
        if ($mot eq $lst_mots[$i][$j]) {
          return $lst_mots[$i][0];
        }
    }
  }

  return "";
}

for (my $file=1; $file <=22; $file=$file+1) {

  if ($file < 10) {
    $file = "0$file";
  }
  open(IN, "harry-potter/part-$file.txt");
  #open(IN, "test$file.txt");
  binmode(IN,':utf8');


  while (my $ligne = <IN>) {
    chop $ligne;
    my @splited_word = split /\s+/,$ligne;
    foreach my $word (@splited_word) {
      if (index($word, "\'") != -1) {
        my $w = substr $word, 0, index($word, "\'");
        $w = "${w}e";
        if ($w eq "") {next;}
        $nombre_mots = $nombre_mots + 1;
        $w = is_mot_plus_utilise($w);
        if ($w ne "") {
          if (exists($mots_plus_utilises{$w})) {
            $mots_plus_utilises{$w} += 1;
          } else {
            $mots_plus_utilises{$w} = 1;
          }
          $nombre_mots_utilises += 1;
        }
      }
      my $word2 = process($word);
      if ($word2 eq "") {next;}
      $nombre_mots = $nombre_mots + 1;
      $word2 = is_mot_plus_utilise($word2);
      if ($word2 ne "") {
        if (exists($mots_plus_utilises{$word2})) {
          $mots_plus_utilises{$word2} += 1;
        } else {
          $mots_plus_utilises{$word2} = 1;
        }
        $nombre_mots_utilises += 1;
      }
    }
  }

  close(IN);
}
my @keys = keys %mots_plus_utilises;
my $size = @keys;
print "- Le nombre totale des mots: $nombre_mots\n";
print "- Le nombre totale des mots plus utilises: $nombre_mots_utilises\n";
my $percent = $nombre_mots_utilises*100/$nombre_mots;
print "- Use of the 50 most common noun words: $percent\n";
print "- Le nombre des mots plus utilises: $size\n";

# foreach my $k (sort keys %data) {
#   print "$k : $data{$k}\n";
# }

foreach my $k (reverse sort {$mots_plus_utilises{$a} <=> $mots_plus_utilises{$b}} keys %mots_plus_utilises) {
  print "[$k] : $mots_plus_utilises{$k}\n";
}
