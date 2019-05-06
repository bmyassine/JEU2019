#include "fonctiondep.h"
int main()
{
    SDL_Surface *ecran =NULL;
    SDL_Surface *image =NULL,*personage=NULL;
    SDL_Rect positionecran,positionpersonage;
    int continuer =1;
   
        int x;

    SDL_Event event; 
    image = IMG_Load("background.png");
    personage=IMG_Load("ennemi.png");
   SDL_SetColorKey(personage, SDL_SRCCOLORKEY, SDL_MapRGB(personage->format, 255, 255, 255));
    positionecran.x=0;
    positionecran.y=0;
    positionpersonage.x=0;
    positionpersonage.y=390;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(900,600, 32, SDL_HWSURFACE );

	

    while (continuer)
    {

        SDL_PollEvent(&event);
        SDL_BlitSurface(image, NULL, ecran, &positionecran);
        SDL_BlitSurface(personage,NULL,ecran,&positionpersonage);
        SDL_Flip(ecran);

			
				
        switch (event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer=0;
                break;
        case SDLK_UP:
                positionpersonage.y=positionpersonage.y-1;
        break;
        case SDLK_DOWN:
                positionpersonage.y=positionpersonage.y+1;
        break;
            case SDLK_RIGHT:
                positionpersonage.x=positionpersonage.x+1;
                break;
            case SDLK_LEFT:
                positionpersonage.x=positionpersonage.x-1;
                break;
        
            }
	break;        
        case SDL_MOUSEBUTTONUP:               
                    
            if (event.button.x>positionpersonage.x){
                positionpersonage.x+=1;
            }
        if (event.button.x<positionpersonage.x){
            positionpersonage.x-=1;
        }
                    break;
    }

}
    SDL_FreeSurface(image);
    SDL_FreeSurface(personage);
 
    return 0;
}
