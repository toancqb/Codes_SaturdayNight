#!/usr/bin/perl

use strict;
use warnings;
use utf8;

binmode(STDOUT, ':utf8');

# define
# NFILE


#  Lire

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
    $numligne = $numligne + 1;
    #my @splited_word = split /\s+/,$ligne;
    foreach my $word ($ligne =~ /[A-Za-z\']+/g) {
    #foreach my $word ($ligne =~ /\w+/g) {
      if (exists($data{$word})) {
        $data{$word} = $data{$word} + 1;
      } else {
        $data{$word} = 1;
      }
    }
  }

  close(IN);
}
my @keys = keys %data;
my $size = @keys;
print "Le nombre des mots: $size\n";

# foreach my $k (sort keys %data) {
#   print "$k : $data{$k}\n";
# }

foreach my $k (reverse sort {$data{$a} <=> $data{$b}} keys %data) {
  print "$k : $data{$k}\n";
}
