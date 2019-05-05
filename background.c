#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
void initialiser_background(background *bckg){


	bckg->calque_background=NULL;
	bckg->calque_background=IMG_Load("background1.png");

	bckg->afficher_background=NULL;
	bckg->afficher_background=IMG_Load("24.png");
	bckg->pos_background.x=0;
	bckg->pos_background.y=0;
	bckg->pos_background2.x=0;
	bckg->pos_background2.y=0;
	bckg->pos_background2.h=600;
	bckg->pos_background2.w=1200;
}
void afficher_background(background bckg,SDL_Surface *ecran){
	
	SDL_BlitSurface(bckg.afficher_background,&(bckg.pos_background2),ecran,&(bckg.pos_background));
}

void scrolling (perso *yassine,background *bckg ,int co)
{int numkeys;
	Uint8 * keys;

	Uint32 timer,elapsed;
	switch(yassine->mouvment)
	{

		case 1: 
			if (co!=2){
			if ((bckg->pos_background2.x<6800)&&(yassine->pos_hero2.x>=300)){
                		bckg->pos_background2.x=bckg->pos_background2.x+5;
			}
			if (((yassine->pos_hero2.x<300)||((bckg->pos_background2.x>=6800))&&(yassine->pos_hero2.x<1100)))
				yassine->pos_hero2.x=yassine->pos_hero2.x+5;
	
	}
		
	
		break;
		case 2:
		if (co!=2){
			if (bckg->pos_background2.x>0)
                		bckg->pos_background2.x=bckg->pos_background2.x-5;
	    		if (((bckg->pos_background2.x!=0)&&(yassine->pos_hero2.x>=150))||((bckg->pos_background2.x==0)&&(yassine->pos_hero2.x=50)))
				yassine->pos_hero2.x=yassine->pos_hero2.x-5;
				}
		break;
		case 3:

		if ((yassine->pos_hero2.y>50)&&(co!=8)){
			if (bckg->pos_background2.x<6800){
				yassine->pos_hero2.y=yassine->pos_hero2.y-5;
				//evan->pos_hero2.x=evan->pos_hero2.x+20;
				//bckg->pos_background2.x=bckg->pos_background2.x+50;
			}
		}
		break;
	}
	if ((yassine->mouvment!=3)&&(co!=10)&&(co!=2)){
		yassine->pos_hero2.y=yassine->pos_hero2.y+5;
	}
}

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



int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col,col2,col22,col1,col3;
  //if(d==0)//imin
  //{
	//col=GetPixel(calque,posperso.x+100+posmap.x,posperso.y+280);
	col2=GetPixel(calque,posperso.x+20+posmap.x,posperso.y+100);
	col22=GetPixel(calque,posperso.x+100+posmap.x,posperso.y+65);
	col3=GetPixel(calque,posperso.x+10+posmap.x,posperso.y);
	//col1=GetPixel(calque,posperso.x+100+posmap.x,posperso.y+240);


 
/*if ((col.r==0)&&(col.b==0)&&(col.g==255))
  return 1;*/
 if ((col22.r==255)&&(col22.b==255)&&(col22.g==255))
  return 2;//obstacle
 else if ((col3.r==255)&&(col3.b==255)&&(col3.g==255))
  return 8;//obstacle
/*else if ((col1.r==0)&&(col1.b==255)&&(col1.g==0))
  return 1;//choukakbira
else if ((col22.r==255)&&(col22.b==0)&&(col22.g==0))
  return 3;//door enigme*/
else if ((col2.r==255)&&(col2.b==255)&&(col2.g==255))
 return 10;//9a3
else
{
	return 0;
}
}
