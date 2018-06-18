#include"../include/Strukturas.h"
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
void Admin::nodzest_Vesturi(string nosaukums){
    int izvele;
    cout<<"Ko gribi nodzest?"<<endl;
    cout<<"1 Kada cilveka vesturi"<<endl;
    cout<<"2 Visu failu ar vesturi"<<endl;

    cin>>izvele;

    switch(izvele){
        case 1: {
            system("cls");
           nosaukums="lietotaji.txt";
            paraditSarakstu(nosaukums);
            cout<<endl;
            string personalID;
            cout<<"Ievadi lietotajas personas kodu::";
            cin>>personalID;
            nosaukums=personalID+"-vesture.txt";
            fstream clear_vesture(string(string(nosaukums)).c_str(),ios::out);
            clear_vesture.close();
            cout<<"Vesture ir veiksmigi nodzesta"<<endl;
            break;
        }
        case 2: {
            system("cls");
            fstream clear_vesture("vesture.txt", ios::out);
            clear_vesture.close();
            cout<<"Vesture ir veiksmigi nodzesta"<<endl;
            break;
        }
    }

}

void Admin::dzest_Lietotajus(){
    string vards, uzvards,login, parole, personalID;
    ifstream file("lietotaji.txt");
    if (file.peek() == ifstream::traits_type::eof()){
        cout<<"Nav neviena pievienota lietotaja"<<endl;
        file.close();
    }else{
            vector<Users> users;
            Users u;
            while (file >> u.login >> u.parole >> u.personalID)
            users.push_back(u);
            file.close();

            cout<<"Ievadi perosnalo kodu ";
            cin>>personalID;

            for (int i=0;i<users.size();i++){
                    if (users[i].personalID==personalID){
                         users.erase(users.begin() + i);
                    }
            }
            ofstream filee("lietotaji.txt");
            for(std::vector<Users>::size_type i = 0; i !=users.size(); i++){
                filee<<users[i].login<<" "<<users[i].parole<<" "<<users[i].personalID<<endl;
            }
            filee.close();
            cout<<"Lietotajs ir veiksmigi nodzests"<<endl;
        }
}

void Admin::meklet_Letotaju(){
	string line;
	string personalID;
	ifstream file("lietotaji.txt");
	if (file.peek() == ifstream::traits_type::eof()){
        cout<<"Nav neviena pievienota lietotaja"<<endl;
        file.close();
    }else{
        cout<<"Ievadi personalo kodu"<<endl;
        cin>>personalID;
        while (getline(file,line)){
            if(line.find(personalID)!=string::npos)
                cout<<line<<endl;
        }
        file.close();
    }
}

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

void Admin::nodzest_reisus(string nosaukums){
    ifstream file(string(string(nosaukums)).c_str());
    if (file.peek() == ifstream::traits_type::eof())
        cout<<"Nav neviena pievienota reisa"<<endl;
            else{
                string line;
                int index;
                vector<string> saraksti;
                while(!file.eof()){
                    getline(file,line);
                    saraksti.push_back(line);
                }
                file.close();
                cout<<"Ievadi saraksta index::";
                cin>>index;
                index--;

                saraksti.erase(saraksti.begin() + index);

                ofstream filee(string(string(nosaukums)).c_str());
                for(std::vector<string>::size_type i = 0; i !=saraksti.size(); i++){
                    filee<<saraksti[i]<<endl;
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
                cout<<"Ievadi veco vardu.::"<<endl;
                cin >> word_old ;

                size_t ind = s.find(word_old);
                if (ind!=string::npos){  //ja ir atrsts
                cout<<"Ievadi jauno vardu.::"<<endl;
                cin >>word_new;
                    s.replace(ind,word_old.size(),word_new);
                     cout<<"Viss ir nomainits"<<endl;
                   }else{
                        cout<<"Tada varda nav"<<endl;
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
                    cout << "7. Nodzest reisus" << endl;
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
                            nodzest_Vesturi(personalID);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 6: {
                            system("cls");
                            meklet_Letotaju();
                             system("pause");
                             system("cls");
                            break;
                        }
                        case 7: {
                            system("cls");
                            int izvele;
                            cout<<"Kadus reisus gribi nodzest ?"<<endl;
                            cout<<"1. Vietejos"<<endl;
                            cout<<"2. Starptautiskos"<<endl;
                            cin>>izvele;
                            switch(izvele){
                            case 1:{
                                system("cls");
                                string nosaukums;
                                nosaukums="saraksts.txt";
                                paraditSarakstu(nosaukums);
                                cout<<endl;
                                nodzest_reisus(nosaukums);
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 2:{
                                system("cls");
                                string nosaukums;
                                nosaukums="starp_saraksts.txt";
                                paraditSarakstu(nosaukums);
                                cout<<endl;
                                nodzest_reisus(nosaukums);
                                system("pause");
                                system("cls");
                                break;
                              }
                            }
                            break;
                        }
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
