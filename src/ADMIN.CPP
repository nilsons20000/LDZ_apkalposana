
#include "../include/Admin.h"
#include "../includeReisi/Reisi.h"

#include <iostream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <time.h>
#include <cstdio>
using namespace std;
Admin::Admin()
{
    //ctor
}

Admin::~Admin()
{
    //dtor
}

void Admin::pievienot_Sarakstu(){
    Reisi * a=new Reisi;

    cout<<"Vietejo sarakstu - 1"<<endl;
    cout<<"Starptautisko sarakstu - 2"<<endl;

    int izvele;
    cin>>izvele;

    switch(izvele){
        case 1:{
            string nosaukums;
            nosaukums="saraksts.txt";
            a->pievienot(nosaukums);
            break;
         }
        case 2:{
            string nosaukums;
            nosaukums="starp_saraksts.txt";
            a->pievienot(nosaukums);
            break;
        }
    }
}
void Admin::nodzest_Vesturi(){
    fstream clear_vesture("vesture", ios::out);
    clear_vesture.close();
}

void Admin::dzest_Lietotajus(){
    string line;
    string s;
    string personalID;
    cout<<"Ievadi perosnalo kodu ";
    cin>>personalID;
    ifstream file("lietotaji.txt");
    ofstream output("lietotajii.txt");
    while(getline(file,line)){
        if(line.find("Personal ID::"+personalID)==string::npos)
         {
            output<<line<<endl;
         }
    }
    file.close();
    output.close();
    remove("lietotaji.txt");
    rename("lietotajii.txt","lietotaji.txt");

}

void Admin::meklet_Letotaju(){
	string line;
	string personalID;
	ifstream file("lietotaji.txt");
	cout<<"Ievadi personalo kodu"<<endl;
	cin>>personalID;
	while (getline(file,line))
	{
		if(line.find(personalID)!=string::npos)
			cout<<line<<endl;
	}

file.close();

}
/*
void Admin::paskatities_Lietotajus(){
    string line;
    ifstream lietotaji("lietotaji.txt");
    while (getline(lietotaji,line)){
        cout<<line<<endl;;
    }
    lietotaji.close();
    system("pause");
}
*/
/*
void Admin::nobloket_Lietotajus(){
    string line;
    int line_now, line_block;
    ifstream lietotaji("lietotaji.txt");
    ofstream block("blokesana.txt",ios::app);
    paskatities_Lietotajus();
    cout<<"Izvelies lietotaju::";
    cin>>line_block;
    line_now=0;
    while (getline(lietotaji, line)){
       line_now++;
        if(line_now!=line_block){
            block<<line<<endl;
        }
    }
    lietotaji.close();
    block.close();
    rename("lietotaji.txt","nobloketi.txt");
    rename("blokesana.txt","lietotaji.txt");

}
*/
void Admin::kludas(){
    cout<<"Kadu sarakstu velaties izlabot?"<<endl;;
    cout<<"1-Vietejo sarakstu"<<endl;
    cout<<"2- Starptautisko sarakstu"<<endl;
    int izvele;
	cin >> izvele;
	switch (izvele) {
	case 1:{
            string nosaukums;
            nosaukums="saraksts.txt";
            kludass(nosaukums);
            break;
	    }
	case 2: {
            string nosaukums;
            nosaukums="starp_saraksts.txt";
            kludass(nosaukums);
            break;
        }
    }
}
void Admin::kludass(string nosaukums){
    system("cls");
    paraditSarakstu(nosaukums);
    ifstream file(string(string(nosaukums)).c_str());

    cout<<"Ievadi rindu::"<<endl;
    string s;
    int number_line_editing, i_number_line_now;
    cin>>number_line_editing;

    i_number_line_now=0;
    ofstream output("saraksts_kludas.txt");

     while(getline(file,s )){
        i_number_line_now++;
          if(i_number_line_now==number_line_editing){
                string word_old; // vecs vards
                string word_new; // jauns vards
                cout<<"Ievadi veco vardu un jauno"<<endl;
                cin >> word_old >> word_new;
                size_t ind = s.find(word_old);
                if (ind!=string::npos){  //ja ir atrsts
                    s.replace(ind,word_old.size(),word_new);
                   }
              }
                output<<s<<endl;

    }
   file.close();
   output.close();
   remove(nosaukums.c_str());
   rename("saraksts_kludas.txt",nosaukums.c_str());
}
void Admin::addmin(){
    system("cls");
    int parole;
    int izeja;
    do{
        cout<<"Ievadiet paroli::"<<endl;
        cin>>parole;
        if (parole==123){
                int izvele;
                system("cls");
                do{
                    cout << "Jus iegajat ka admin" << endl;
                    cout << "1. Paradit sarakstu" << endl;
                    cout << "2. Paradit sarakstu Starptautiskiem vilcieniem" << endl;
                    cout << "3. Paradit lietotaajus" << endl;
                    cout << "4. Paradit vesturi" << endl;
                    cout << "5. Nodzest vesturi" << endl;
                    cout << "6. Meklet lietotajus" << endl;
                   // cout << "7. Nobloket lietotajus" << endl;
                    cout << "8. Pievienot sarakstu" << endl;
                    cout << "9. Izlabot kludas"<<endl;
                    cout << "10.Nodzest lietotajus"<<endl;
                    cout << "0. Iziet" <<endl;


                    cin >> izvele;
                    switch (izvele) {
                        case 1:{
                            string nosaukums;
                            nosaukums="saraksts.txt";
                            system("cls");
                            paraditSarakstu(nosaukums);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 2: {
                            string nosaukums;
                            nosaukums="starp_saraksts.txt";
                            system("cls");
                            paraditSarakstu(nosaukums);
                             system("pause");
                             system("cls");
                            break;
                        }
                        case 3: {
                            string nosaukums;
                            nosaukums="lietotaji.txt";
                            system("cls");
                            paraditSarakstu(nosaukums);
                             system("pause");
                             system("cls");
                            break;
                        }
                        case 4: {
                            string nosaukums;
                            nosaukums="vesture.txt";
                            system("cls");
                            paraditSarakstu(nosaukums);
                             system("pause");
                             system("cls");
                            break;
                        }
                        case 5: {
                            system("cls");
                            nodzest_Vesturi();
                             system("pause");
                            break;
                        }
                        case 6: {
                            system("cls");
                            meklet_Letotaju();
                             system("pause");
                             system("cls");
                            break;
                        }
                        //case 7: {
                            //system("cls");
                           // nobloket_Lietotajus();
                            //break;
                        //}
                        case 8: {
                            system("cls");
                            pievienot_Sarakstu();
                             system("pause");
                             system("cls");
                            break;
                        }
                        case 9: {
                            system("cls");
                            kludas();
                             system("pause");
                             system("cls");
                            break;
                        }
                        case 10: {
                            system("cls");
                            dzest_Lietotajus();
                             system("pause");
                             system("cls");
                            break;
                        }
                        case 0: break;
                        default: cout<<"Ievadi ciparu 0 - 10!"<<endl;
                        system("pause");
                    }
                }while(izvele!=0);
        }else
        cout<<"Pameginiet valreiz"<<endl;
        cout<<"Gribi atkartot? 1=Ja; 0=Ne:";
        cin>>izeja;
    }while(izeja);
}
