#include "struct.h"
void Render(perso *p,SDL_Surface* screen)
{
	SDL_Rect R;
	R.x = (Sint16)p->pos_hero2.x;
	R.y = (Sint16)p->pos_hero2.y;
	R.w = 20;
	R.h = 40;
	//SDL_FillRect(screen,&R,SDL_MapRGB(screen->format,0,255,0));
 // SDL_BlitSurface(p->perframe,NULL,screen,&R);
SDL_BlitSurface(p->afficher_hero,NULL,screen,&p->pos_hero2);
	
}

void Saute(perso *p,float impulsion)
{
	p->vy = -impulsion;
	p->status = STAT_AIR;
}

void ControleSol(perso *p)
{
	if (p->pos_hero2.y>500)
	{
		p->pos_hero2.y = 500;
		if (p->vy>0)
			p->vy = 0.0f;
		p->status = STAT_SOL;
	}
}

 void Gravite(perso *p,float factgravite,float factsautmaintenu,Uint8* keys)
{
	if (p->status == STAT_AIR && keys[SDLK_SPACE])
		factgravite/=factsautmaintenu;
	p->vy += factgravite;
}

void Evolue(perso *p,Uint8* keys)
{  
   int i=1;
	float lateralspeed = 0.5f;
	float airlateralspeedfacteur = 0.5f;
	float maxhspeed = 2.0f;
	float adherance = 1.5f;
	float impulsion = 2.0f;
	float factgravite = 1.0f;
	float factsautmaintenu = 2.0f;
// controle late  ral
  
	if  (p->status == STAT_AIR) // (*2)
		lateralspeed*= airlateralspeedfacteur;
	if (keys[SDLK_LEFT]) // (*1)
		p->vx-=lateralspeed;
	if (keys[SDLK_RIGHT])
		p->vx+=lateralspeed;
	if (p->status == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
		p->vx/=adherance;
// limite vitesse
	if (p->vx>maxhspeed) // (*4)
		p->vx = maxhspeed;
	if (p->vx<-maxhspeed)
		p->vx = -maxhspeed;
// saut
	if (keys[SDLK_SPACE] )
		Saute(p,impulsion);
	Gravite(p,factgravite,factsautmaintenu,keys);
	ControleSol(p);
// application du vecteur à la position.
	p->pos_hero2.x +=p->vx;
	p->pos_hero2.y +=p->vy;

}

