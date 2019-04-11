#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "definitions.h"
 
void init2(bouton b[5])
{
b[0].image = IMG_Load("pictures/leslvl/lvl1.png");
b[1].image = IMG_Load("pictures/leslvl/lvl2off.png");
b[2].image = IMG_Load("pictures/leslvl/lvl3off.png");


b[0].pos.x =100 ;
b[0].pos.y =90;

b[1].pos.x =340;
b[1].pos.y =20 ;

b[2].pos.x =560 ;
b[2].pos.y =90 ;

}



int jeux(SDL_Surface *ecran)
{
int i;
SDL_Surface *ecran1=NULL;
//declaration boutton
bouton b[3];
init2(b);
//declaration background
SDL_Rect pos;
pos.x=0;
pos.y=50;
SDL_Init(SDL_INIT_VIDEO);
//ouverture fenetre jeux
SDL_Surface *bg = NULL;
ecran= SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("jeu", NULL);
//intialisation background
bg = IMG_Load("pictures/bg.png");
SDL_BlitSurface(bg, NULL,ecran,&pos);
for (i=0;i<3;i++)
SDL_BlitSurface(b[i].image, NULL, ecran, &(b[i].pos));
SDL_Flip(ecran);


int continuer = 1;
SDL_Event event;
while(continuer)
{

   SDL_PollEvent(&event);

     if (event.type == SDL_QUIT)
     {
       continuer = 0;
     }

else if( event.type == SDL_MOUSEBUTTONDOWN )
   { if( event.button.button == SDL_BUTTON_LEFT )
        {
          if ((event.button.x > b[0].pos.x) && (event.button.x < b[0].pos.x + b[0].pos.w) && (event.button.y > b[0].pos.y) && (event.button.y < b[0].pos.y + b[0].pos.h))
                 stage1(ecran1);


}

}




 




















}
}
