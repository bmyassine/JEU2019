#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "time.h"
#include "SDL/SDL.h"

#include<math.h>
#include "enigm.h"

#include "SDL/SDL_ttf.h"

int main(void)
{ SDL_Surface *screen; 
 screen = NULL; 
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(952,535,24,SDL_HWSURFACE | SDL_DOUBLEBUF);//taille de fenetre
SDL_WM_SetCaption( "enigmes dynamique", NULL ); // nom de fenetre 

int n=0;int fact,r;

	
  


	

n=generate_question(&n);

init_affichier_question(n,screen);
fact=resolution(n);

r=reponse(&r);
printf("%d %d",r,fact);//afficher f terminal 
afficher_resultat (screen,fact, r);

SDL_Quit();
return 0;

}
