#include "include\Admin.h"
#include "include\Klients.h"
#include "include\Lietotajs.h"
#include "include\Viesis.h"

#include"../include/Strukturas.h"
#include "includeLDZ_sistema\LDZ_sistema.h"

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH =800;
const int SCREEN_HEIGHT = 600;


SDL_Window *window = NULL;
SDL_Renderer *renderer =NULL;

SDL_Texture* LoadImage(std::string file){
   SDL_Surface *loadedImage = NULL;
   SDL_Texture *texture = NULL;
   loadedImage = SDL_LoadBMP(file.c_str());
   if (loadedImage != NULL){
       texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
       SDL_FreeSurface(loadedImage);
   }
   else
       std::cout << SDL_GetError() << std::endl;
   return texture;
}

int main(int argc, char** argv){

   if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
       std::cout << SDL_GetError() << std::endl;
       return 1;
   }

   window = SDL_CreateWindow("Latvijas Dzelzcels", SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
   if (window == NULL){
       std::cout << SDL_GetError() << std::endl;
       return 2;
   }
   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
       | SDL_RENDERER_PRESENTVSYNC);
   if (renderer == NULL){
       std::cout << SDL_GetError() << std::endl;
       return 3;
   }

   SDL_Texture *background = NULL, *image = NULL;
   background = LoadImage("bmp2.bmp");
   image = LoadImage("bmp1.bmp");
   if (background == NULL || image == NULL)
       return 4;
       SDL_RenderClear(renderer);

   int bW, bH;
   SDL_QueryTexture(background, NULL, NULL, &bW, &bH);

   Lietotajs a;

   a.ApplySurface(0, 0, background, renderer);


   int iW, iH;
   SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
   int x = SCREEN_WIDTH / 2 - iW / 2;
   int y = SCREEN_HEIGHT / 2 - iH / 2;


   a.ApplySurface(x, y, image, renderer);

   SDL_RenderPresent(renderer);
   SDL_Delay(2000);

   SDL_DestroyTexture(background);
   SDL_DestroyTexture(image);
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();

    	int izvele;
    do{
	Klients a;
	Viesis b;
	Admin c;
	LDZ_sistema d;
    system("cls");
    cout << "Jus iegajat LDZ aplikacija." << endl;
	cout<<"1 Registreties"<<endl;
	cout<<"2 Viesis "<<endl;
	cout<<"3 Klients "<<endl;
	cout<<"4 Admin"<<endl;
	cout << "5. Iziet" <<endl;
	cin>>izvele;
	switch(izvele){
		case 1: d.registreties();
			break;
		//4://
			//break;
        case 2: b.vviesis();
            break;
		case 3: a.Klientss();
			break;
		case 4: c.addmin();
            break;
        case 5: break;
        default: cout<<"Ievadi ciparu 1 - 5!"<<endl; break;

	}
}while(izvele!=5);
    return 0;
}
