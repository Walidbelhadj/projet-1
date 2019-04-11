#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"

int main()
{ 

	SDL_Surface *screen;
	enigme  e;
	int s,r,run =1,running=1,alea;
	char image[30]="";
	SDL_Event event;
    srand(time(NULL));
   
	 
	 SDL_Init ( SDL_INIT_VIDEO ) ;



	 screen=SDL_SetVideoMode(1024,630,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
	 init_enigme(&e);
	
	 while (run)
	 {
	    running=1,r=0 ;
	     SDL_PollEvent(&event);
           switch(event.type)
            {
              case SDL_QUIT:
                run = 0;
			  break ;
            }	

        	
      generate_afficher ( screen,image ,&e,&alea) ;}
 
 }
	        
