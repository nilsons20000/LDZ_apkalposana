#ifndef REISI_H
#define REISI_H

#include <string>
using namespace std;
class Reisi
{
    public:
        Reisi();
        virtual ~Reisi();


        void pievienot(string);

        Reisi(string, string, string,string, string);

        void setVilcienaNumurs(string, string);
        void setMarsruts(string,string );
        void setLaiks(string,string );
        void setCena(string, string);
    protected:

    private:
        string vilcienaNumurs;
		string marsruts;
        string laiks;
        string cena;
        string nosaukums;
};

#endif // REISI_H
