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

my $mt = "villad";
print_lst_mots(@lst_mots);
# print "$lst_mots[1][0]\n";
# @lst_mots = process_Noun_data(@lst_mots);
# print_lst_mots(@lst_mots);

#my $res = is_mot_plus_utilise($mot);
#print "$res\n"
