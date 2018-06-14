#ifndef BILETE_H
#define BILETE_H

#include <string>

using namespace std;

class Bilete
{
    public:
        Bilete();
        virtual ~Bilete();
        void drukasana(string);
        void bileteDR(std::string,std::string,std::string,std::string,std::string,std::string);//vards,uzvards,maarsruts, laiks
    protected:

    private:
};

#endif // BILETE_H
