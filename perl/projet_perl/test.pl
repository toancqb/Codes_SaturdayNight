use strict;
use warnings;
use utf8;

binmode(STDOUT, ':utf8');

#my @lst_color_mots = (
my @lst_mots = (
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
  my ($word, $nombre_mots_utilisesx, %mots_plus_utilisesx) = @_;
  $word = is_mot_plus_utilise($word);
  if ($word ne "") {
    $mots_plus_utilisesx{$word} += 1;
    $nombre_mots_utilisesx += 1;
  }
}

my $n1 = 0;
my %mots_plus_utilises;

manipuler_word("gris", $n1, %mots_plus_utilises);

foreach my $k (reverse sort {$mots_plus_utilises{$a} <=> $mots_plus_utilises{$b}} keys %mots_plus_utilises) {
  #print "-=[$k]=- : $mots_plus_utilises{$k}\n";
  print_color('bold black on_white', "-=[");
  print color('bold red on_yellow');
  printf("%-10s", $k); print color('reset');
  print_color('bold black on_white', "]=- : ");
  print color('bold black on_cyan');
  printf("%8i", $mots_plus_utilises{$k}); print color('reset');
  print color('on_white'), "                          \n", color('reset');
  
}
