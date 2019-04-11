#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enemy.h"
Enemy AnimateEnemy(Enemy Ennemie,int stat)
{
  if (Ennemie.fram==2) {
    Ennemie.fram=0;
  }
  else
  Ennemie.fram++;
  Ennemie.imageActuel=Ennemie.image[Ennemie.fram];
  if(stat==1)
    Ennemie.imageActuel=Ennemie.Hit;
  return Ennemie;

}
