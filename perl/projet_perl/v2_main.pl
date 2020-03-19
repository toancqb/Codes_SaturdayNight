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

##################################

my %mots_plus_utilises;
my $nombre_mots = 0;
my $nombre_mots_utilises = 0;

###################################
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

###################################

for (my $file=1; $file <=22; $file=$file+1) {

  if ($file < 10) {
    $file = "0$file";
  }
  open(IN, "harry-potter/part-$file.txt");
  binmode(IN,':utf8');

  while (my $ligne = <IN>) {
    chop $ligne;
    my @splited_word = split /\s+/,$ligne;
    foreach my $word (@splited_word) {
      if (index($word, "\'") != -1) {
        my $w1 = substr $word, 0, index($word, "\'");
        $w1 = "${w1}e";
        $nombre_mots = $nombre_mots + 1;
        manipuler_word($w1);
      }
      my $w2 = process($word);
      if ($w2 eq "") {next;}
      $nombre_mots = $nombre_mots + 1;
      manipuler_word($w2)
    }
  }
  close(IN);
}

sub print_color {
  print color($_[0]), $_[1], color('reset');
}

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

##################################

my %mots_plus_utilises2;
my $nombre_mots2 = 0;
my $nombre_mots_utilises2 = 0;

###################################


sub manipuler_word2 {
  my $word = $_[0];
  $word = is_mot_plus_utilise($word);
  if ($word ne "") {
    $mots_plus_utilises2{$word} += 1;
    $nombre_mots_utilises2 += 1;
  }
}

open(IN, "stevenson-fr-v2.txt");
binmode(IN,':utf8');



while (my $ligne = <IN>) {
  chop $ligne;
  my @splited_word = split /\s+/,$ligne;
  foreach my $word (@splited_word) {
    if (index($word, "\'") != -1) {
      my $w1 = substr $word, 0, index($word, "\'");
      $w1 = "${w1}e";
      $nombre_mots2 = $nombre_mots2 + 1;
      manipuler_word2($w1);
    }
    my $w2 = process($word);
    if ($w2 eq "") {next;}
    $nombre_mots2 = $nombre_mots2 + 1;
    manipuler_word2($w2);
  }
}
close(IN);




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
