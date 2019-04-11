#include<stdlib.h>
#include <stdio.h>
#include<string.h> 
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include"init.h"

void init_cle(cle* c){
    c->img[0] = IMG_Load("1.gif");
    c->valeur=10;
}

void main()
{
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
int i=1;
cle c;
SDL_Rect pos; 
pos.x=0;
pos.y=0;
SDL_Surface* bg; 
bg=SDL_SetVideoMode(500,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
init_cle(&c);

while(1)
{

SDL_BlitSurface(c.img[0], NULL,bg,&pos);
SDL_Flip(bg);

}

SDL_Quit();

}
