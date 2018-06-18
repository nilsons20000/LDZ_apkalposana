
#include "..\include\Viesis.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <stdlib.h>
#include <stdio.h>
using namespace std;
Viesis::Viesis()
{
    //ctor
}

Viesis::~Viesis()
{
    //dtor
}
void Viesis::vviesis(){
    int izvele;
    do{
        system("cls");
	    cout << "Jus iegajat ka viesis LDZ aplikacija" << endl;
		cout<<"1 Paradit sarakstu"<<endl;
		cout<<"2 Paradit Sarakstu Starptautiskiem vilcieniem"<<endl;

		cin >> izvele;
		switch(izvele){

             case 1:{
                string nosaukums;
                nosaukums="saraksts.txt";
                system("cls");
                cout<<"Numurs, marsruts, laiks, cena"<<endl;
                paraditSarakstu(nosaukums);
                system("pause");
                        system("cls");
                break;
            }
             case 2: {
                string nosaukums;
                nosaukums="starp_saraksts.txt";
                system("cls");
                cout<<"Numurs, marsruts, laiks, cena"<<endl;
                paraditSarakstu(nosaukums);
                system("pause");
                        system("cls");
                break;
            }
             case 0: break;
                default: cout<<"Ievadi ciparu 0 - 10!"<<endl;
                system("pause");
       }
    }while(izvele!=0);
}



