#ifndef KLIENTS_H
#define KLIENTS_H

#include "Lietotajs.h"

#include <iostream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <time.h>
using namespace std;
class Klients : public Lietotajs
{
    public:
		Klients();

        virtual ~Klients();

		//
        //ir
		//
		void MekletVilcienu();//ir
		void filtretaMeklesana(string,string);//ir
		//
		void Print_Info(string);//ir
		void paradit_Kontu(string);//ir
		//
		void Nopirkt_Bileti(string);//ir
		//
		void vesture();//ir
		//
		void nodzest_Kontu(string,string );
		void mainit_paroli(string,string,string);//mainit paroli
        void Klientss();//ir
        void Jusu_vesture(string);

        void nopirkt(string,string);

    protected:

    private:
};

#endif // KLIENTS_H
