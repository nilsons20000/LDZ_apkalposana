#ifndef ADMIN_H
#define ADMIN_H

#include "Lietotajs.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Admin : public Lietotajs
{
    public:
        Admin();
        virtual ~Admin();
        void pievienot_Sarakstu();//ir
		void paskatities_Lietotajus();//ir
		void meklet_Letotaju();//ir
		void nodzest_Vesturi();//ir
        void addmin();//ir
		void dzest_Lietotajus();//ir
		//void nobloket_Lietotajus();
		void kludas();
        void kludass(string);
    protected:

    private:
};

#endif // ADMIN_H
