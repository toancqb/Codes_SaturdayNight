#!/usr/bin/perl

use strict;
use warnings;
use utf8;


my @lst_mots = (
    ("maison","maisons"),
    ("ville","villes"),
    ("fois")
);

my %mots_plus_utilises;
#my @splited_word;
my $nombre_mots = 0;

# sub process_Noun_data {
#   my @lst = @_;
#
#   foreach my $tab (@lst) {
#     my $str = "";
#     foreach my $m ($tab) {
#       if (substr($m, -1) ne "s") {
#         $str = "${m}s";
#       }
#     }
#     if ($str ne "") {
#       push(@{$tab}, $str);
#     }
#   }
#   return @lst;
# }

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
  foreach my $tab (@lst_mots) {
    foreach my $m ($tab) {
      if ($mot eq $m) {
        return 1;
      }
    }
  }
  return 0;
}

# my $mt = "villad";
# print_lst_mots(@lst_mots);
# print "$lst_mots[1][0]\n";
# @lst_mots = process_Noun_data(@lst_mots);
# print_lst_mots(@lst_mots);

#my $res = is_mot_plus_utilise($mot);
#print "$res\n"
my %d;

$d{'0'} += 1;
$d{'1'} += 1;
$d{'1'} += 1;

foreach my $k (sort keys %d) {
  print "$k : $d{$k}\n";
}


## backup

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

##
