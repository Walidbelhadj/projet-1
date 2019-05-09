/**
* @file voiture.c
*/
#include <SDL/SDL.h>
#include "defs.h"
#include "voiture.h"
#include "background.h"
/**
* @brief To initialize the loadvoiture A.
* @param A the loadvoiture
* @param url the url of the image
* @return Nothing
*/


int loadVoitureImages(Voiture * A)
{
	int i;
	char buf[50];
	char buf0[]="../images/tankScout";
	char bmp[]=".bmp";
	
	for(i=0; i<NBRE_SPRITE; i++) {
		sprintf(buf,"%s%d%s",buf0,i,bmp);
		A->image[i] = SDL_LoadBMP(buf);
		if (A->image[i]== NULL) {
			printf("Unable to load  Voiture bitmap:\n", SDL_GetError());
			return (-1);
		}
		// set the color of Voiture background (white color) as transparent
		SDL_SetColorKey( A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 255, 255, 255) );
	}
	return(0);
}
/**
* @brief To initialize the initvoiture A.
* @param A the initvoiture
* @param url the url of the image
* @return Nothing
*/
void initVoiture(Voiture *A)
{
	A->direction=0;
	A->position.x=190;  
	A->position.y=SCREEN_H - A->image[0]->h;
	A->position.w=A->image[0]->w;
	A->position.h=A->image[0]->h;
	A->score=0;
	A->vie=5;
	A->velocity=2; //5km/h
	A->acceleration=0;
	A->Mass=70;
	A->moving=0;
	A->fire=0;
}
/**
* @brief To initialize the deplacement A.
* @param A the deplacement
* @param url the url of the image
* @return Nothing
*/
void deplacerVoiture(Voiture *A,Background *B,Uint32 dt)
{
	/*Dx = vit + ½at2
	 * displacement = initial velocity * time + ½ acceleration * time2
	 * */
	A->velocity+=0.5*A->acceleration*dt;
	B->backgroundPos.x+=A->velocity*dt;

}


void freeVoiture(Voiture *A)
{
	int i;
	for(i=0; i<NBRE_SPRITE; i++)
		SDL_FreeSurface(A->image[i]);
}
