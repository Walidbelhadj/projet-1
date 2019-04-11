#include "map.h"
#include "player.h"
#include "collision.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "definitions.h"

 

int stage1(SDL_Surface *ecran)
{//declaration background
SDL_Rect pos;
pos.x=0;
pos.y=0;
SDL_Init(SDL_INIT_VIDEO);
//ouverture fenetre jeux
ecran= SDL_SetVideoMode(1000,963,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Level 1", NULL);
//intialisation background
BackGround bg;
bg=InitBackGround(bg,"pictures/stage1/lvl1.png","pictures/stage1/calque.png");
AfficherBackGround(bg,ecran);
SDL_Flip(ecran);
//intialistion player
Player Joueur;
Joueur=InitPlayer(Joueur);
AfficherPlayer(Joueur,ecran);
int continuer=1;
int direction=0;
int x;
SDL_Event event;
while(continuer)
{SDL_PollEvent(&event);

        if(event.type==SDL_QUIT)
          {
                     continuer=0;
          }
  else if(event.type==SDL_KEYDOWN)
        {
            if(event.key.keysym.sym==SDLK_RIGHT) direction=0;
            if(event.key.keysym.sym==SDLK_LEFT)  direction=1;
            if(event.key.keysym.sym==SDLK_UP)    {direction=2;}
            if(event.key.keysym.sym==SDLK_DOWN)  {direction=3;}
        }
 Joueur=MovePlayer(Joueur,direction,x);
AfficherBackGround(bg,ecran);
AfficherPlayer(Joueur,ecran);
SDL_Flip(ecran);
}

    



















}
