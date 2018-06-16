#include "../include/Klients.h"
#include"../include/Strukturas.h"
#include "Lietotajs.h"
#include "Konts.h"
#include "Bilete.h"
#include <iostream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <vector>
using namespace std;
Klients::Klients()
{
}
Klients::~Klients()
{
    //dtor
}


void Klients::paradit_Kontu(string personalID){
    string nosaukums;
    nosaukums=personalID+"-Konts.txt";
    paraditSarakstu(nosaukums);
}
void Klients::nopirkt(string file,string personalID){
    string nosaukumss;
    nosaukumss=personalID+"-Konts.txt";
    ifstream kont(string(string(nosaukumss)).c_str());
    if (kont.peek() == ifstream::traits_type::eof()){
            cout<<"Nav neviena pievienota konta"<<endl;
            kont.close();
        }else{
                vector<Kontss> kontss;
                int index;

                Kontss u;
                while (kont >> u.numurs >> u.nauda_konta)
                kontss.push_back(u);
                kont.close();

                string num, laikss, nauda, uzKurieni;
                string line;

                ifstream saraksts(string(string(file)).c_str());
                int line_number_now;
                int line_number_chose;

                cout<<"Ievadi biletes numuru::";
                cin>>line_number_chose;

                fflush(stdin);

                line_number_now=0;
                while(!saraksts.eof()){
                    line_number_now++;
                        if (line_number_now==line_number_chose){
                            getline(saraksts,num,',');
                            getline(saraksts,uzKurieni,',');
                            getline(saraksts,laikss,',' );
                            getline(saraksts,nauda);

                            double out;
                            stringstream st;
                            st << nauda;
                            st >> out;

                            int i =0;
                            for (vector<Kontss>::iterator it=kontss.begin();it!=kontss.end();it++){
                                i++;
                                cout<<i<<" "<<it->numurs<<"  "<<it->nauda_konta<<endl;
                            }

                            cout<<"Ievadi konta index::";
                            cin>>index;
                            index--;
                            cout<<kontss[index].numurs<<" "<<kontss[index].nauda_konta<<endl;
                            cout<<endl;

                            double outt;
                            stringstream stt;
                            stt << kontss[index].nauda_konta;
                            stt >> outt;

                            double  summa;
                            if(outt>out)
                                summa=outt-out;
                                 else{
                                    cout<<"Nepietiek lidzekljus"<<endl;
                                    break;
                                }
                                ofstream vesture(string(string("vesture.txt")).c_str(),ios::app);
                                ofstream vestureID(string(string(personalID)+"-vesture.txt").c_str(),ios::app);

                                vestureID<<personalID<<" "<<num<<" "<<uzKurieni<<" "<<laikss<<" "<<nauda<<" "<<endl;
                                vesture<<personalID<<" "<<num<<" "<<uzKurieni<<" "<<laikss<<" "<<nauda<<" "<<endl;

                                vestureID.close();
                                vesture.close();

                                string result;
                                stringstream sttt;
                                sttt << summa;
                                sttt >> result;

                                kontss[index].nauda_konta=result;
                                cout<<endl;

                                Kontss uu;
                                kontss.push_back(uu);

                                cout<<endl;

                                ofstream kont(string(string(nosaukumss)).c_str());
                                for(std::vector<Kontss>::size_type i = 0; i !=kontss.size(); i++){
                                    kont<<kontss[i].numurs<<" "<<kontss[i].nauda_konta<<endl;
                                }
                                cout<<"Bilete tiek nopirkta"<<endl;
                        break;
                        }
                }
                kont.close();
        }
}
void Klients::filtretaMeklesana(string personalID, string nosaukums){
    string VilcienaNR;
    string laiks;
    string n;
    string line;
    int i;

    cout<<"Ievadi vilciena numuru: ";
    cin>>VilcienaNR;

    ifstream file(string(string(nosaukums)).c_str());
    if (file.peek() == ifstream::traits_type::eof())
            cout<<"Sarakstu nav"<<endl;
        else{
            ofstream output("vilcienaNR.txt");
            while(getline(file,line)){
                if (line.find("Numurs "+VilcienaNR)!=string::npos){
                        cout<<line<<endl;
                        output<<line<<endl;
                    }
            }
            file.close();
            output.close();
            cout<<"Ievadi laiku 'piem. 10-21' ::";
            cin>>laiks;

            ifstream filee("vilcienaNR.txt");
            if (filee.peek() == ifstream::traits_type::eof())
                    cout<<"tuks"<<endl;
                else{
                    ofstream outputt("vilcienaLaiks.txt");
                    fflush(stdin);
                    i=0;
                    while (getline(filee,line)){
                        if(line.find("Laiks="+laiks)!=string::npos){
                            i++;
                            outputt<<line<<endl;
                            cout<<i<<line<<endl;
                          }
                        }
                        filee.close();
                        outputt.close();
                        int izvele;
                        string numurs;string laikss;string nauda;string uzKurieni;

                        cout<<"Gribi nopirkt bileti? 1-Ja 0-Ne::";
                        cin>>izvele;

                        if(izvele){
                            system("cls");
                            string nosaukums;
                            nosaukums="vilcienaLaiks.txt";
                            paraditSarakstu(nosaukums);
                            nopirkt(nosaukums,personalID);
                        }
                    }
            }
}
void Klients::Print_Info(string personalID){
    int izvele;
    ifstream file("lietotaji.txt");
    string line;
    while (getline(file,line)){
        if(line.find(personalID)!=string::npos)
            cout<<line<<endl;
    }
    file.close();
    cout<<"Gribi noskatities Kontu? 1-Ja 2-Ne::";
    cin>>izvele;
    switch(izvele){
        case 1: {
            system("cls");
            string nosaukums;
            nosaukums=personalID+"-Konts.txt";
            paraditSarakstu(nosaukums);
            break;
        }
    }
                cout<<"Gribi nodzest kontu?1-Ja 2-Ne::";
                cin>>izvele;
                switch(izvele){
                    case 1: {
                        system("cls");
                        string nosaukums;
                        nosaukums=personalID+"-Konts.txt";
                        nodzest_Kontu(nosaukums,personalID);
                        break;
                    }
                }
}

void Klients::Nopirkt_Bileti(string personalID){
   string numurs, laikss, nauda, uzKurieni;
    cout<<"Kadu bileti gribi nopirkt?"<<endl;
    cout<<"1-Vietejies biletes"<<endl;
    cout<<"2-Starptautiskie biletes"<<endl;
    int izvele;
    string line;
    cin>>izvele;
    switch(izvele){
        case 1: {
            system("cls");
            string nosaukums;
            nosaukums="saraksts.txt";
            paraditSarakstu(nosaukums);
            nopirkt(nosaukums,personalID);
            break;
        }
        case 2:{
            system("cls");
            string nosaukums;
            nosaukums="starp_saraksts.txt";
            paraditSarakstu(nosaukums);
            nopirkt(nosaukums,personalID);
            break;
        }
    }
}

void Klients::mainit_paroli(string login,string parole,string personalID){
    string  w_old,w_new;
    ifstream lietotaji("lietotaji.txt");
    ofstream lietotaji_temp("lietotaji_temp.txt");
    string line;
    while(getline(lietotaji,line)){
        if(line.find(login)!=string::npos && line.find(personalID)!=string::npos){
            cout<<"Ievadi  jauno paroli"<<endl;
            cin>> w_new;
            size_t ind = line.find(parole);
                if (ind!=string::npos){//ja ir atrsts
                  line.replace(ind,parole.size(),w_new);
                }
        }
                  lietotaji_temp<<line<<endl;
    }
    lietotaji.close();
    lietotaji_temp.close();
    remove("lietotaji.txt");
    rename ("lietotaji_temp.txt","lietotaji.txt");
}
void Klients::nodzest_Kontu(string nosaukums,string personalID){
    ifstream kont(string(string(nosaukums)).c_str());
    if (kont.peek() == ifstream::traits_type::eof()){
        cout<<"Nav neviena pievienota konta"<<endl;
        kont.close();
    }
            else{
                vector<Kontss> kontss;
                int index;
                {
                    ifstream kont(string(string(nosaukums)).c_str());
                    Kontss u;
                    while (kont >> u.numurs >> u.nauda_konta)
                    kontss.push_back(u);
                    kont.close();
                }
                int i=0;
                for (vector<Kontss>::iterator it=kontss.begin();it!=kontss.end();it++){
                    i++;
                    cout<<i<<" "<<it->numurs<<"  "<<it->nauda_konta<<endl;
                }

                cout<<"Ievadi konta index::";
                cin>>index;
                index--;
                cout<<kontss[index].numurs<<" "<<kontss[index].nauda_konta<<endl;
                cout<<endl;

                kontss.erase(kontss.begin() + index);

                ofstream kont(string(string(nosaukums)).c_str());
                for(std::vector<Kontss>::size_type i = 0; i !=kontss.size(); i++){
                    kont<<kontss[i].numurs<<" "<<kontss[i].nauda_konta<<endl;
                }
                cout<<"Konts tiek nodzests"<<endl;
            }
}

void Klients::Klientss(){
    system("cls");
	string login; string parole; string personalID;
	cout << "Ievadi login:: ";
	cin >> login;

	cout<<"Ievadi paroli::";
	cin >> parole;

	cout<<"Ievadi personalo kodu(ID)::";
	cin >> personalID;

	vector<Users> users;
    ifstream fin("lietotaji.txt");
    Users u;
    while (fin >> u.login >> u.parole >>u.personalID)
    users.push_back(u);
    fin.close();
	bool flag=true;
    for (int i=0;i<users.size();i++){
        if (users[i].login==login && users[i].parole==parole && users[i].personalID==personalID){
                int izvele;
                system("cls");
                do{
                    cout << "Jus iegajat ka lietotajs" << endl;
                    cout << "1. Paradit sarakstu" << endl;
                    cout << "2. Paradit sarakstu Starptautiskiem vilcieniem" << endl;
                    cout << "3. Filtreta Meklesana" << endl;
                    cout << "4. Paradit informaciju par sevi (Print_Info)" << endl;
                    cout << "5. Pievienot kontu" << endl;
                    cout << "6. Nopirkt bileti" << endl;
                    cout << "7. Mainit paroli" << endl;
                    cout << "8. Apskatit savas  biletes"<<endl;
                    cout << "9.Izdrukat bileti"<<endl;
                    cout << "0. Iziet "<<endl;
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
                            int izvele;
                            system("cls");
                            cout<<"Kadu bileti pirksiet?"<<endl;
                            cout<<"1- Vietejo. 2-Starptautisko"<<endl;
                            cin>>izvele;
                            switch(izvele){
                                case 1:{
                                    string nosaukums;
                                    nosaukums="saraksts.txt";
                                    system("cls");
                                    filtretaMeklesana(personalID,nosaukums);
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                                 case 2:{
                                    string nosaukums;
                                    nosaukums="starp_saraksts.txt";
                                    system("cls");
                                    filtretaMeklesana(personalID,nosaukums);
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                            }
                            break;
                    }
                    case 4: {
                        system("cls");
                        Print_Info(personalID);
                        system("pause");
                        system("cls");
                        break;
                    }
                    case 5:{
                        system("cls");
                        Konts *a=new Konts;
                        a->pievienot_Kontu(personalID);
                        system("pause");
                        system("cls");
                        break;
                    }
                    case 6: {
                        system("cls");
                        Nopirkt_Bileti(personalID);
                        system("pause");
                        system("cls");
                        break;
                    }
                    case 7: {
                        system("cls");
                        mainit_paroli(login, parole, personalID);
                        system("pause");
                        system("cls");
                        break;
                    }
                    case 8:{
                        string nosaukums;
                        nosaukums=personalID+"-vesture.txt";
                        system("cls");
                        paraditSarakstu(nosaukums);
                        system("pause");
                        system("cls");
                        break;
                    }
                    case 9:{
                        system("cls");
                        string nosaukums;
                        nosaukums=personalID+"-vesture.txt";
                        paraditSarakstu(nosaukums);
                        Bilete *a=new Bilete;
                        a->drukasana(personalID);
                        system("pause");
                        system("cls");
                        break;
                    }

                    case 0: break;
                    default: cout<<"Ievadi ciparu 0 - 10!"<<endl;
                    system("pause");
                    system("cls");
                    }
                }while(izvele!=0);
                 flag=false;
                break;
            }
        }
        if (flag){
            system("cls");
            cout<<"Nepareizs login, parole vai ID "<<endl;
            Sleep(1000);
        }
}
