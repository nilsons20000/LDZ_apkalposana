#ifndef VILCIENANUMURS_H
#define VILCIENANUMURS_H

#include <Marsruts.h>

#include <iostream>
#include <string>
using namespace std;

class VilcienaNumurs : public Marsruts
{
    public:
        VilcienaNumurs();
        virtual ~VilcienaNumurs();
        VilcienaNumurs(string);
        VilcienaNumurs(string, string );
        void setVilcienaNumurs(string, string);

    protected:

    private:
};

#endif // VILCIENANUMURS_H
