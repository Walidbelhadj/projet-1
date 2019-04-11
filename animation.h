#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct perso
{
  SDL_Surface *image[3];
  SDL_Surface *Hit;
  SDL_Surface *imageActuel;
  SDL_Rect position;
  int fram;
  int direction;

}perso;
perso Initperso(perso personnage,int x,int y);
void  Afficherperso(perso personnage,SDL_Surface *screen);
void moveperso(SDL_Rect camera,perso *personnage,int direction);
