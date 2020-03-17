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
#  Lires

my %data = ();
#my @splited_word;
my $numligne = 0;



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
        my $w = substr $word, 0, index($word, "\'");
        $w = "${w}e";
        if ($w eq "") {next;}
        $numligne = $numligne + 1;
        if (exists($data{$w})) {
          $data{$w} = $data{$w} + 1;
        } else {
          $data{$w} = 1;
        }
      }
      my $word2 = process($word);
      if ($word2 eq "") {next;}
      $numligne = $numligne + 1;
      if (exists($data{$word2})) {
        $data{$word2} = $data{$word2} + 1;
      } else {
        $data{$word2} = 1;
      }
    }
  }

  close(IN);
}
my @keys = keys %data;
my $size = @keys;
print "Le nombre totale des mots: $numligne\n";
print "Le nombre des mots uniques apres conjugasion: $size\n";

# foreach my $k (sort keys %data) {
#   print "$k : $data{$k}\n";
# }

foreach my $k (reverse sort {$data{$a} <=> $data{$b}} keys %data) {
  print "[$k] : $data{$k}\n";
}
