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
my $nombre_mots = 0;
my $nombre_phrases = 0;



for (my $file=1; $file <=22; $file=$file+1) {

  if ($file < 10) {
    $file = "0$file";
  }
  open(IN, "harry-potter/part-$file.txt");
  #open(IN, "test$file.txt");
  binmode(IN,':utf8');


  while (my $ligne = <IN>) {
    chop $ligne;
    my @phrases = split /[!?.]/, $ligne;
    $nombre_phrases += scalar @phrases;
    foreach my $phrase (@phrases) {
      #my @splited_word = split /\s+/,$phrase;
      foreach my $word (split /\s+/,$phrase) {
        if (index($word, "\'") != -1) {
          my $w = substr $word, 0, index($word, "\'");
          $w = "${w}e";
          if ($w eq "") {next;}
          $nombre_mots = $nombre_mots + 1;
        }
        my $word2 = process($word);
        if ($word2 eq "") {next;}
        $nombre_mots = $nombre_mots + 1;
      }
    }
  }

  close(IN);
}

print "Le nombre des mots: [$nombre_mots]\n";
print "Le nombre des phrases: [$nombre_phrases]\n";
my $moyenne = $nombre_mots / $nombre_phrases;
print "Le moyenne des mots par phrase: [$moyenne]\n";
