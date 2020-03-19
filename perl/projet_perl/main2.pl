#!/usr/bin/perl


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

my $percent = $nombre_mots_utilises2*100/$nombre_mots2;

print color('bold black on_green'), "- Use of the 50 most common noun words:    ", color('reset');
print color('bold red on_yellow');
printf("%9.2f%%\n", $percent); print color('reset');

print color('bold black on_green'), "- Le nombre des mots plus utilises:        ", color('reset');
print color('bold red on_yellow');
printf("%10i\n",$size); print color('reset');
##
my $top = 1;
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


#
# open(IN, "harry-potter/part-$file.txt");
# binmode(IN,':utf8');
#
# while (my $ligne = <IN>) {
#   chop $ligne;
#   my @splited_word = split /\s+/,$ligne;
#   foreach my $word (@splited_word) {
#     if (index($word, "\'") != -1) {
#       my $w1 = substr $word, 0, index($word, "\'");
#       $w1 = "${w1}e";
#       $nombre_mots = $nombre_mots + 1;
#       manipuler_word($w1);
#     }
#     my $w2 = process($word);
#     if ($w2 eq "") {next;}
#     $nombre_mots = $nombre_mots + 1;
#     manipuler_word($w2)
#   }
# }
# close(IN);
#
# my @keys = keys %mots_plus_utilises;
# my $size = @keys;
# ##
# print color('bold black on_green'), "- Le nombre totale des mots:               ", color('reset');
# print color('bold red on_yellow');
# printf("%10i\n", $nombre_mots); print color('reset');
#
# print color('bold black on_green'), "- Le nombre totale des mots plus utilises: ", color('reset');
# print color('bold red on_yellow');
# printf("%10i\n",$nombre_mots_utilises); print color('reset');
#
# my $percent = $nombre_mots_utilises*100/$nombre_mots;
#
# print color('bold black on_green'), "- Use of the 50 most common noun words:    ", color('reset');
# print color('bold red on_yellow');
# printf("%9.2f%%\n", $percent); print color('reset');
#
# print color('bold black on_green'), "- Le nombre des mots plus utilises:        ", color('reset');
# print color('bold red on_yellow');
# printf("%10i\n",$size); print color('reset');
# ##
# my $top = 1;
# foreach my $k (reverse sort {$mots_plus_utilises{$a} <=> $mots_plus_utilises{$b}} keys %mots_plus_utilises) {
#   #print "-=[$k]=- : $mots_plus_utilises{$k}\n";
#   print_color('bold black on_white', "-=[");
#   print color('bold red on_yellow');
#   printf("%-10s", $k); print color('reset');
#   print_color('bold black on_white', "]=- : ");
#   print color('bold black on_cyan');
#   printf("%8i", $mots_plus_utilises{$k}); print color('reset');
#   print color('on_white'), "                          \n", color('reset');
#   if ($top >= 20) {
#     last;
#   }
#   $top += 1;
# }
