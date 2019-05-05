#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
 #include <unistd.h>
#include <math.h>
#include "struct.h"
void initialiser_pmap(pmap *pmap){

	pmap->afficher_pmap=NULL;
	pmap->afficher_pmap=IMG_Load("pmap.png");

	pmap->pos_pmap.x=300;
	pmap->pos_pmap.y=120;


	pmap->afficher_pperso=NULL;
	pmap->afficher_pperso=IMG_Load("pperso.png");

	pmap->pos_pperso.x=301;
	pmap->pos_pperso.y=120;
	pmap->nbmoved=0;


}

void afficher_pmap(pmap *pmap,SDL_Surface *ecran,int mouvment){


	SDL_BlitSurface(pmap->afficher_pmap,NULL,ecran,&pmap->pos_pmap);

	SDL_BlitSurface(pmap->afficher_pperso,NULL,ecran,&pmap->pos_pperso);
	if (mouvment==1)
		pmap->nbmoved++;
	if (mouvment==2)
		pmap->nbmoved--;

		if (pmap->nbmoved==9){
		pmap->pos_pperso.x+=2;
		pmap->nbmoved=0;
}
	if (pmap->nbmoved==-9){
		pmap->pos_pperso.x-=2;
		pmap->nbmoved=0;
	}

}
