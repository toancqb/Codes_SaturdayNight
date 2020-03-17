#!/usr/bin/perl

use strict;
use warnings;
use utf8;


sub process {
  my $word = lc($_[0]);
  $word = substr $word, index($word, "\'") + 1;
  return $word;
}

sub process2 {
  my $word = "";
  if ($_[0] eq "-" || $_[0] eq "!" || $_[0] eq "?" || $_[0] eq "—") {
    return ""
  }
  $word = lc($_[0]);
  $word = substr $word, index($word, "\'") + 1;
  return $word;
}

sub process3 {
  my $word = "";
  my @lst = ("", "");
  if ($_[0] eq "-" || $_[0] eq "!" || $_[0] eq "?"
    || $_[0] eq "—"|| $_[0] eq ":" || $_[0] eq "»"
    || $_[0] eq "«"|| $_[0] eq ";") {
    return @lst;
  }
  $word = lc($_[0]);
  my $n = index($word, "\'");
  if ($n != -1) {
    my $tmp = substr $word, 0, 1;
    $tmp = "${tmp}e";
    push(@lst, $tmp);
  } else {
    push(@lst, "");
  }
  $word = substr $word, $n + 1;
  $word =~ s/[\.\,\(\)\…\»]//g;
  push(@lst, $word);
  return @lst;
}

my @str = process3("?");
print "$str[0]\n$str[1]\n";

# for (my $file=1; $file <=1; $file=$file+1) {
#
#   if ($file < 10) {
#     $file = "0$file";
#   }
#   open(IN, "harry-potter/part-$file.txt");
#   binmode(IN,':utf8');
#
#
#   while (my $ligne = <IN>) {
#     chop $ligne;
#     $numligne = $numligne + 1;
#     my @splited_word = split /\s+/,$ligne;
#     foreach my $word (@splited_word) {
#       my @lst=("", "");
#       @lst = process($word);
#       if ($lst[1] eq "") {next;}
#       for (my $i=0; $i <=1; $i=$i+1) {
#         if ($i == 0 && $lst[$i] eq "") {next;}
#         if (exists($data{$lst[$i]})) {
#           $data{$lst[$i]} = $data{$lst[$i]} + 1;
#         } else {
#           $data{$lst[$i]} = 1;
#         }
#       }
#     }
#   }
#
#   close(IN);
# }
