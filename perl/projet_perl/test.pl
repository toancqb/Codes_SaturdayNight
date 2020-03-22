use strict;
use warnings;
use utf8;

use Term::ANSIColor;

binmode(STDOUT, ':utf8');

sub cherche_mot {
  my $mot = $_[0];
  my $fichier = $_[1];
  my $numligne = 0;

  open(IN, $fichier);
  binmode(IN,':utf8');

  print color('bold blue'),"[$fichier]: \n",color('reset');

  while (my $ligne = <IN>) {
    chop $ligne;
    $numligne += 1;

    if ($ligne =~ /^(.*)($mot\w*)(.*)$/) {

      my $gauche = $1;
      my $motif  = $2;
      my $droite = $3;

      if (length($gauche)>30) {
        $gauche = substr($gauche,-30,30);
      }

      # vvv ajouts par rapport à la version 2 vvv
      my @mots = split(/\W+/,$droite);
      $droite = '';
      my $maxmots = 5;
      if (scalar(@mots)<$maxmots) {
        $maxmots = scalar(@mots);
      }
      for (my $i=0 ; $i<$maxmots ; $i=$i+1) {
        $droite = $droite.$mots[$i].' ';
      }
      # ^^^ ajouts par rapport à la version 2 ^^
      #

      print color('bright_magenta');
      printf("%5i: ",$numligne);
      print color('reset');

      print color('bold white');
      printf("%30s",$gauche);
      print color('reset');

      print color('green on_white');
      printf("%-10s",$motif);
      print color('reset');

      print color('bold white'),$droite,color('reset');
      print "\n";
      }
  }
  close(IN);
}

cherche_mot("pass", "stevenson/stevenson-fr-v2.txt");
