#ifndef KONTS_H
#define KONTS_H

#include <string>
using namespace std;
class Konts
{
    public:
        Konts();
        virtual ~Konts();

        Konts(string, string);

		void pievienot_Kontu(string);//daleji ir
		void setKontaNumurs(string,string);//daleji ir

    protected:

    private:
        string personalID;
		string kontaNumurs;
};
#endif // KONTS_H
