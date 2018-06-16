#include "Konts.h"
#include <iostream>
#include <string>
#include <fstream>

#include "cstdlib"
using namespace std;
Konts::Konts()
{
    //ctor
}

Konts::~Konts()
{
    //dtor
}
Konts::Konts(string  kontaNumurs,string personalID){
	this->setKontaNumurs(kontaNumurs,personalID);
}


void Konts::pievienot_Kontu(string personalID ){
	cout << "Ievadi konta numuru: ";
	cin >> kontaNumurs ;
	Konts newKonts(kontaNumurs, personalID);
}
void Konts::setKontaNumurs(string kontaNumurs, string personalID){
    string k;
    string f;
    long random(void);
    f=personalID;
    k="-Konts.txt";
	ofstream file(string(string(f)+k).c_str(),ios::app);
    int a=rand() % 100;
	file<<kontaNumurs<<" "<<a<<endl;
    cout<<"Konts "<<kontaNumurs<<" tiek pievienots"<<endl;
	file.close();
}
