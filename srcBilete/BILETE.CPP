#include "Bilete.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include<string>

using namespace std;
Bilete::Bilete()
{
    //ctor
}

Bilete::~Bilete()
{
    //dtor
}
void Bilete::drukasana(string personalID){
    string line,numurs,uzKurieni,laikss,nauda,n;
    int line_number_now;
    int line_number_chose;
    string vards,uzvards;

    cout<<"Ievadi vardu:";
    cin>>vards;

    cout<<"Ievadi uzvardu:";
    cin>>uzvards;

    line_number_now=0;

    n=personalID+"-vesture.txt";
    ifstream biletes(string(string(n)).c_str());
    cout<<"Izveles bilete::";
    cin>>line_number_chose;
    while(!biletes.eof()){
        line_number_now++;
            if (line_number_now==line_number_chose){
                getline(biletes,numurs,',');
                getline(biletes,uzKurieni,',');
                getline(biletes,laikss,',' );
                getline(biletes,nauda);
                    Bilete *a= new Bilete;
                    a->bileteDR(vards,uzvards,numurs,uzKurieni,laikss,nauda);
                }
    }
      biletes.close();
}

void Bilete::bileteDR(string vards,string uzvards,string numurs,string uzKurieni,string laikss,string nauda){
    ofstream htmlfails;
    htmlfails.open("fails.html");

    htmlfails << "<!DOCTYPE html>" << endl;
    htmlfails << "<html>" << endl;
    htmlfails << "<head>" << endl;
    htmlfails << "<style>" << endl;
    htmlfails << "table, th, td {" << endl;
    htmlfails << "    border: 1px solid black;" << endl;
    htmlfails << "    border-collapse: collapse;" << endl;
    htmlfails << "}" << endl;
    htmlfails << "</style>" << endl;
    htmlfails << "</head>" << endl;
    htmlfails << "<body>" << endl;
    htmlfails << "<table style=\"width:500px\">" << endl;
    htmlfails << "  <tr>" << endl;
    htmlfails << "  </tr>" << endl;
    htmlfails << "  <tr>" << endl;
    htmlfails << "    <td>" << vards<<" "<<uzvards << "</td>" << endl;
    htmlfails << "    <td>" << numurs << "</td>" << endl;
    htmlfails << "  </tr>" << endl;
    htmlfails << "  <tr>" << endl;
    htmlfails << "    <td>Marsruts</td>" << endl;
    htmlfails << "    <td>" << uzKurieni << "</td>" << endl;
    htmlfails << "  </tr>" << endl;
    htmlfails << "  <tr>" << endl;
    htmlfails << "    <td>Laiks</td>" << endl;
    htmlfails << "    <td>" <<laikss<< "</td>" << endl;
    htmlfails << "  </tr>" << endl;
    htmlfails << "  <tr>" << endl;
    htmlfails << "    <td>Cena</td>" << endl;
    htmlfails << "    <td>" << nauda << "</td>" << endl;
    htmlfails << "  </tr>" << endl;
    htmlfails << "  <tr>" << endl;
    htmlfails << "  </tr>" << endl;
    htmlfails << "</table>" << endl;
    htmlfails << "</body>" << endl;
    htmlfails << "</html>" << endl;

    htmlfails.close();
}

