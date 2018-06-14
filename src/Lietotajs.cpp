
#include "..\include\Lietotajs.h"
#include <iostream>
#include <string>
#include <fstream>

#include <SDL2/SDL.h>

using namespace std;
Lietotajs::Lietotajs()
{
    //ctor
}

Lietotajs::~Lietotajs()
{
    //dtor
}

void Lietotajs::ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
   SDL_Rect pos;
   pos.x = x;
   pos.y = y;
   SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
   for(double i =0.0; i<=360.0; i+=2){
       SDL_RenderCopyEx(rend, tex, NULL, &pos,i,NULL,SDL_FLIP_NONE);
       SDL_RenderPresent(rend);
   }
}
void Lietotajs::paraditSarakstu(string nosaukums){
	string line;
	ifstream file(string(string(nosaukums)).c_str());
	int i=0;
	while (getline(file, line)){
        i++;
		cout <<i<<":"<< line << endl;
	}
	file.close();
}

