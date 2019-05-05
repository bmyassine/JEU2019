#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
#include <time.h>
#include <unistd.h>

void affichiervie(perso yassine, SDL_Surface *ecran){
	SDL_BlitSurface(yassine.afficher_vie[yassine.vie],NULL,ecran,&yassine.pos_vie);
}
int gestionvie(perso *yassine, SDL_Surface *ecran,background *bckg){
	
	
	if((yassine->hit==1)&&(yassine->vie!=0)){
		yassine->vie--;
	affichiervie(*yassine,ecran);
	SDL_Flip(ecran);
	usleep(1000000);
	bckg->pos_background2.x=0;
	bckg->pos_background2.y=0;
	yassine->pos_hero2.y=0;
	yassine->pos_hero2.x=0;
	}
	yassine->hit=0;
	if (yassine->vie==0)
	return 0;
	else return 1;

}
