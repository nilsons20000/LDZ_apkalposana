#ifndef LIETOTAJS_H
#define LIETOTAJS_H

#include <iostream>
#include <string>
#include <fstream>
#include <SDL2/SDL.h>
using namespace std;
class Lietotajs
{
    public:

        string login;
        string parole;
        string vards;
        string uzvards;
        string personalID;

        Lietotajs();
        virtual ~Lietotajs();

        SDL_Texture* LoadImage(std::string );
        void ApplySurface(int , int , SDL_Texture *tex, SDL_Renderer *rend);

        void paraditSarakstu(string);//ir
        void pievienot(string);

    protected:

    private:

};

#endif // LIETOTAJS_H
