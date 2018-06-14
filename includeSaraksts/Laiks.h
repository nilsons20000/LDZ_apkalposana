#ifndef LAIKS_H
#define LAIKS_H

#include <Marsruts.h>

#include <iostream>
#include <string>
using namespace std;

class Laiks : public Marsruts
{
    public:
        Laiks();
        virtual ~Laiks();
        Laiks(string);
        Laiks(string,  string );
        void setLaiks(string,string );

    protected:

    private:
};

#endif // LAIKS_H
