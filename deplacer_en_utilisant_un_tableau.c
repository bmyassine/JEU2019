#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


int collision(SDL_Rect* rect1 ,SDL_Rect* rect2)
{
        if(rect1->y >= rect2->y + rect2->h)
                return 0;
        if(rect1->x >= rect2->x + rect2->w)
                return 0;
        if(rect1->y + rect1->h <= rect2->y)
                return 0;
        if(rect1->x + rect1->w <= rect2->x)
                return 0;
        return 1;
}





int main (int argc , char *argv[])
{


// ce qu'on ecrit ici ne changent pas avec les events q'on fait !!!!




SDL_Init(SDL_INIT_VIDEO);


SDL_Surface *ecran=NULL  , *map=NULL , *player=NULL ;


ecran=SDL_SetVideoMode(800 , 600 , 32 , SDL_HWSURFACE);

int tab[4]={0,0,0,0};


SDL_Rect rect , rect2 , position;
rect.x= 10 ;
rect.y= 10 ; 

rect.w= 20 ;
rect.h= 20 ;


rect2.x= 50 ;
rect2.y= 50 ; 

rect2.w= 50 ;
rect2.h= 10 ;



position.x=400 ;
position.y= 300 ;



map=IMG_Load("map.jpg");
player=IMG_Load("player.png");



Uint32 color=SDL_MapRGB(ecran->format , 255 , 255, 255);

Uint32 color1=SDL_MapRGB(ecran->format , 0 ,0,  0);

Uint32 start ;
const int FPS=30; 


int continuee=1 ;
SDL_FillRect(ecran , &rect2 , color);

while (continuee)
{

start=SDL_GetTicks();


SDL_BlitSurface(map , NULL , ecran , NULL);


SDL_Event event ;

while(SDL_PollEvent(&event))
{




switch(event.type)
{




case SDL_QUIT :
continuee=0 ;
break ;

case SDL_KEYDOWN :

switch (event.key.keysym.sym)
{
case SDLK_UP :

tab[0]=1;
break;


case SDLK_DOWN :
tab[1]=1;
break ;


case SDLK_LEFT :
tab[2]=1;
break ;

case SDLK_RIGHT :
tab[3]=1;
break ;

}

break ;





case SDL_KEYUP :

switch (event.key.keysym.sym)
{

case SDLK_UP :
tab[0]=0;
break ;

case SDLK_DOWN :
tab[1]=0;
break ;


case SDLK_LEFT :
tab[2]=0;
break ;

case SDLK_RIGHT :
tab[3]=0;
break ;

}
break ;





}




}



SDL_BlitSurface(player , NULL , ecran , &position);

SDL_FillRect(ecran , &rect , color1);

if (tab[0])
{
rect.y-- ;

if (collision( &rect ,&rect2))

{

rect.y++ ;

}

}


if (tab[1])
{

rect.y++ ;


if (collision(& rect,&rect2))

{

rect.y-- ;

}

}







if (tab[2])
{
rect.x-- ;

if (collision(& rect,&rect2))

{

rect.x++ ;

}


}

if (tab[3])
{
rect.x++ ;

if (collision(& rect,&rect2))

{

rect.x-- ;

}


}


SDL_FillRect(ecran , &rect , color);
SDL_Flip(ecran);



if (1000/FPS > SDL_GetTicks()-start)
SDL_Delay(1000/FPS - (SDL_GetTicks()-start));


}




SDL_Quit();
}

















