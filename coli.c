#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coli.h"

SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;

	
	char* pPosition = ( char* ) surface->pixels ;

	pPosition += ( surface->pitch * y ) ;

	
	pPosition += ( surface->format->BytesPerPixel * x ) ;

	
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;

	
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}
int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,int decalage,int d)
{

  SDL_Color col;
  if(d==0)//imin
  {
    col=GetPixel(calque,posperso.x+perso->w +decalage,posperso.y+(perso->h/2));
  }
else  if(d==1)//issarr
  {
    col=GetPixel(calque,posperso.x +decalage,posperso.y+(perso->h/2));
  }
else  if(d==2)//lfou9
  {
    col=GetPixel(calque,posperso.x+(perso->w/2)+decalage ,posperso.y);
  }
else  if(d==3)//louta
  {
    col=GetPixel(calque,posperso.x+(perso->w/2) +decalage,posperso.y+perso->h);
  }
  //printf("%d    %d   %d\n",col.r,col.b,col.g );
if ((col.r==255)&&(col.b==255)&&(col.g==255))
{
  return 1;
}
else return 0;
}
