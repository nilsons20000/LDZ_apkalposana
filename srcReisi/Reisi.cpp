#include "Reisi.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Reisi::Reisi()
{
    //ctor
}

Reisi::~Reisi()
{
    //dtor
}
void Reisi::pievienot(string nosaukums){
    string vilcienaNumurs;string marsruts;string laiks; string cena;

	cout << "Ievadi vilciena numuru numuru: ";
	cin >> vilcienaNumurs;

	cout << "Ievadi marsrutu: ";
	cin >> marsruts;

	cout << "Ievadi laiku: ";
	cin >> laiks;

	cout << "Ievadi cenu: ";
	cin >> cena;

    Reisi(vilcienaNumurs,marsruts,laiks,cena,nosaukums);
}

Reisi::Reisi(string VilcienaNumurs,string marsruts,string laiks,string cena,string nosaukums){
    this->setVilcienaNumurs( vilcienaNumurs,  nosaukums);
    this->setMarsruts( marsruts, nosaukums);
    this->setLaiks(laiks, nosaukums);
    this->setCena( cena,nosaukums);
}

void Reisi::setVilcienaNumurs(string vilcienaNumurs,string nosaukums){
	ofstream file(string(string(nosaukums)).c_str(),ios::app);
	file<<vilcienaNumurs<<",";
	file.close();
}

void Reisi::setMarsruts(string marsruts,string nosaukums){
	ofstream file(string(string(nosaukums)).c_str(),ios::app);
	file<<marsruts<<",";
	file.close();
}

void Reisi::setLaiks(string laiks,string nosaukums){
	ofstream file(string(string(nosaukums)).c_str(),ios::app);
	file<<"Laiks="<<laiks<<",";
	file.close();
}

void Reisi::setCena(string cena,string nosaukums){
	ofstream file(string(string(nosaukums)).c_str(),ios::app);
	file<<cena<<","<<endl;
	file.close();
}









