#include <stdio.h> 
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct {
    SDL_Surface* img[3];
    Mix_Music* m;
}asse;

void init_assen(asse* a){
    a->img[0] = IMG_Load("ass f.png");
    a->img[1] = IMG_Load("ass o.png"); 
}
void main(){
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
int i=0 ;
asse a;
SDL_Rect pos; 
pos.x=0;
pos.y=0;
SDL_Surface* bg; 
bg=SDL_SetVideoMode(300,300,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
init_assen(&a);

while(1){
SDL_Delay(80);
SDL_BlitSurface(a.img[i%2],NULL,bg,&pos); SDL_Flip(bg);
i++;
}
SDL_Quit();
}
