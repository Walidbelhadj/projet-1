#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "animation.h"
perso Initperso(perso personnage,int x,int y)
{
  personnage.image[0]=IMG_Load("graphique/Enemy/rpg1.png");
  personnage.image[1]=IMG_Load("graphique/Enemy/rpg2.png");
  personnage.image[2]=IMG_Load("graphique/Enemy/rpg3.png");
  personnage.Hit=IMG_Load("graphique/Enemy/rpg4.png");
  personnage.imageActuel=Ennemie.image[0];
  personnage.position.x=x;
  personnage.position.y=y;
  personnage.fram=0;
  personnage.direction=0;
  return personnage;
}
void moveperso(SDL_Rect camera,perso *personnage,int direction)
{if(direction==0)
personange->position.x-=camera.x;
if(direction==1)
personnage->position.x+=camera.x;

}
void  Afficherperso(perso personnage,SDL_Surface *screen)
{
  SDL_BlitSurface(personnage.imageActuel,NULL,screen,&personnage.position);
}
