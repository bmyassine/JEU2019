#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <SDL/SDL_rotozoom.h>
#define TEMPS       10
#define STAT_SOL 0
#define STAT_AIR 1
typedef struct pmap{
	int nbmoved;
	SDL_Surface *afficher_pmap;
	SDL_Rect pos_pmap;
	SDL_Surface *afficher_pperso;
	SDL_Rect pos_pperso;

}pmap;
typedef struct logo{

	SDL_Surface *afficher_logo;
	SDL_Rect logo;
	
}logo;
typedef struct background{

	SDL_Surface *afficher_background;
	SDL_Rect pos_background;
	SDL_Rect pos_background2;
	SDL_Surface *calque_background;
}background;

typedef struct Enemy
{
  SDL_Surface *image[3];
  SDL_Surface *image2[3];
  SDL_Surface *Hit;
  SDL_Surface *imageActuel;
  SDL_Rect position;
  SDL_Rect positionO;
  int frame;
  int direction;

}Enemy;

typedef struct personnage{

	SDL_Surface *afficher_hero;
	SDL_Rect pos_hero;
	SDL_Rect pos_hero2;
	int mouvment;
	int farm;
	int vie;
	SDL_Surface *afficher_vie[4];
	int hit;
	SDL_Rect pos_vie;
	float vx,vy;
int status;
}perso;
typedef struct objet{

	SDL_Surface *afficher_objet;
	SDL_Rect pos_objet;
}objet;
typedef struct 
{
	SDL_Surface *img;
	SDL_Rect pos;
}coin;
void anim_perso(int *i,perso *p);
void initialiser_pmap(pmap *pmap);
void afficher_pmap(pmap *pmap,SDL_Surface *ecran,int mouvment);
void initialiser_background(background *bckg);
void afficher_background(background bckg,SDL_Surface *ecran);
void initialiser_perso(perso *yassine);
void afficher_perso(perso yassine,SDL_Surface *ecran);
void scrolling (perso *yassine,background *bckg,int co);
int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);
int mouvment(perso yassine,SDL_Event *event);
void initialiser_objet(objet *dabouza);
void afficher_objet(objet *dabouza,SDL_Surface *ecran,perso yassine);
int animation_perso(perso yassine);
float carree(float x);
int trigooo(perso *yassine,coin *c);
void affichiervie(perso yassine, SDL_Surface *ecran);
int gestionvie(perso *yassine, SDL_Surface *ecran,background *bckg);
int Collision_Bounding_Box (perso yassine ,objet dabouza );
int quite (SDL_Surface *ecran);
int quit (SDL_Surface *ecran);
Enemy InitEnemy(Enemy Ennemie,int x, int y);
Enemy AnimateEnemy(Enemy Ennemie,int stat);
void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen);
Enemy MoveEnemy(Enemy Ennemie,SDL_Rect personnage,int *stat,int mouvment);
void enigme2(SDL_Surface *screen,int *rep);
int generate_question(int*n);
void init_affichier_question(int n,SDL_Surface *screen);
int resolution(int n);
int reponse(int *rep );
void afficher_resultat (SDL_Surface * screen,int solution,int r);
void initialiser_logo(logo *l);
void afficher_logo(logo *l,SDL_Surface *ecran);
SDL_Surface * rotozoomSurface (SDL_Surface *src, double angle, double zoom, int smooth);
int rotozoom(SDL_Surface *ecran,SDL_Surface *image);
void Saute(perso* Sp,float impulsion);
void ControleSol(perso* Sp,int i);
void Gravite(perso* Sp,float factgravite,float factsautmaintenu,SDL_Event keys);

#endif
