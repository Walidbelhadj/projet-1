#include "definitions.h"

void music()
{
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
	printf("%s",Mix_GetError());
	}
	Mix_Music *music;
	music = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music,-1);
    	}

int showmenu(SDL_Surface* screen)
{
  SDL_Surface *play=NULL,*settings=NULL,*credits=NULL,*exit=NULL,*cursor=NULL,*menu=NULL,*playo=NULL,*settingso=NULL,*exito=NULL,*ecran=NULL;
   
    SDL_Rect position,playpos,settingspos,creditspos,exitpos,cursorpos;
    SDL_Event event;
    
    int continuer = 1,volume=1;
    int x,y,i=0;
	
        position.x=0;
 	position.y=0;
	playpos.x=350;
	playpos.y=300;
	settingspos.x=350;
	settingspos.y=360;
	creditspos.x=350;
	creditspos.y=420;
	exitpos.x=350;
	exitpos.y=430;
	cursorpos.x=100;
	cursorpos.y=playpos.y-10;
        menu=IMG_Load("pictures/1.png");
        cursor=IMG_Load("pictures/Cursor.png");
        play=IMG_Load("pictures/start.gif");
	settings=IMG_Load("pictures/setings.gif");
	exit=IMG_Load("pictures/exit.gif");
        playo=exit=IMG_Load("pictures/exito.gif");
settingso=settings=IMG_Load("pictures/setingso.gif");
exito=IMG_Load("pictures/exito.gif");
  
   SDL_BlitSurface(menu,NULL,screen,&position);
   SDL_BlitSurface(play,NULL,screen,&playpos);
   SDL_BlitSurface(settings,NULL,screen,&settingspos);
   SDL_BlitSurface(exit,NULL,screen,&exitpos);
   music();
        
        while(1)
	{     
		
                while(SDL_PollEvent(&event))
                {  
            
                    switch(event.type)
                        {
                                case SDL_QUIT:
					return(0);
					
                                        	
                                        break;
                                case SDL_MOUSEMOTION:
                                          case SDL_MOUSEBUTTONDOWN:
                                        x = event.motion.x;
                                        y = event.motion.y;
					if(x>=playpos.x && x<=playpos.x+playpos.w && y>=playpos.y && y<=playpos.y+playpos.h)
						{
                                                
							play=IMG_Load("pictures/starto.gif");
							cursorpos.y=playpos.y-10;
                                                                      if(event.button.button == SDL_BUTTON_LEFT)
                                                                                  
                                                         jeux(screen);

						}
						else
							play=IMG_Load("pictures/start.gif");
				 	
					if(x>=settingspos.x && x<=settingspos.x+settingspos.w && y>=settingspos.y && y<=settingspos.y+settingspos.h)
						{
                                                        settings=IMG_Load("pictures/setingso.gif");
							cursorpos.y=settingspos.y-10;
                                                                     if(event.button.button == SDL_BUTTON_LEFT)
                                 
                                                         menuson(&volume);    

                      
					}
						else
							settings=IMG_Load("pictures/setings.gif");
					
					if(x>=exitpos.x && x<=exitpos.x+exitpos.w && y>=exitpos.y && y<=exitpos.y+exitpos.h)
						{
                                                
							exit=IMG_Load("pictures/exito.gif");
							cursorpos.y=exitpos.y-10;
						 	case SDL_MOUSEBUTTONUP:
                                                        if ((event.button.button == SDL_BUTTON_LEFT)&&(x>=exitpos.x && x<=exitpos.x+exitpos.w && y>=exitpos.y && y<=exitpos.y+exitpos.h))
                                                        return(0);
                                                        break;	 	
						}
						else
							exit=IMG_Load("pictures/exit.gif");
					break;
                      		
		      }
		}
                   SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
		   SDL_BlitSurface(menu,NULL,screen,&position);
		   SDL_BlitSurface(play,NULL,screen,&playpos);
		   SDL_BlitSurface(settings,NULL,screen,&settingspos);
		   SDL_BlitSurface(exit,NULL,screen,&exitpos);
		   SDL_Flip(screen);
             
	}

	return(continuer);

}


int main(void)
{
SDL_Surface *screen = NULL,*menu=NULL;
  
int continuer = 1;
SDL_Event event;

SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption("ENNIGMA", NULL);



     
 while (continuer)
    {
        
        continuer=showmenu(screen);

	
   }

    
   

    
   
    SDL_Quit();

    return EXIT_SUCCESS;
}

