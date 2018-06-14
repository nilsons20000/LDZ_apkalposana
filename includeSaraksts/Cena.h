#ifndef CENA_H
#define CENA_H

#include <Marsruts.h>

#include <iostream>
#include <string>
using namespace std;


class Cena : public Marsruts
{
    public:
        Cena();
        virtual ~Cena();
        Cena(string);
        Cena(string,string);
        void setCena(string, string);
    protected:

    private:
};

#endif // CENA_H
