#ifndef MARSRUTSS_H
#define MARSRUTSS_H

#include <Marsruts.h>

#include <iostream>
#include <string>
using namespace std;

class marsrutss : public Marsruts
{
    public:
        marsrutss();
        virtual ~marsrutss();
        marsrutss(string);
        marsrutss(string,  string);
        void setMarsruts(string,string );
    protected:

    private:
};

#endif // MARSRUTSS_H
