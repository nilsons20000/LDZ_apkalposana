#ifndef MARSRUTS_H
#define MARSRUTS_H


#include <iostream>
#include <string>
using namespace std;

class Marsruts
{
    public:

        Marsruts();
        virtual ~Marsruts();
        void pievienot(string);

    private:
		string vilcienaNumurs;
		string marsruts;
        string laiks;
        string cena;
        string nosaukums;
};

#endif // MARSRUTS_H
