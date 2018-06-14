#include "LDZ_sistema.h"

LDZ_sistema::LDZ_sistema()
{
    //ctor
}

LDZ_sistema::~LDZ_sistema()
{
    //dtor
}
void LDZ_sistema::registreties()
{
    string vards, uzvards,login, parole, personalID;
    vector<Users> users;
    ifstream fin("lietotajii.txt");
    Users u;
    while (fin >> u.login >> u.parole >> u.personalID)
    users.push_back(u);
    fin.close();
    cout<<"Ievadi vardu::";
    cin>>vards;
    cout<<"Ievadi uzvardu::";
    cin>>uzvards;
    bool  flagg=true;
    do{
        flagg=true;
        cout<<"Ievadi login::";
        cin>>login;

        for (int i=0;i<users.size();i++){
            if (users[i].login!=login)
                cout<<"ok";

            else{
                cout<<"Tads jau eksiste"<<endl;
                flagg=false;
                break;
            }
        }
    }while(!flagg);
    cout<<"Ievadi paroli::";
    cin>>parole;

    do{
        flagg=true;
        cout<<"Ievadi personal ID::";
        cin>>personalID;
        for (int i=0; i<users.size(); i++){
            if (users[i].personalID!=personalID)
                    cout<<"ok";
                else
                    {
                        cout<<"Tads jau eksiste";
                        flagg=false;
                        break;
                    }
                }
    }while(!flagg);
    ofstream fout("lietotaji.txt", ios::app);
    fout<<login<<" "<<parole<<" "<<personalID<<" "<<vards<<" "<<uzvards<<endl;
    cout<<"Regestracija bija veiksmiga"<<endl;
    Sleep(1000);
    system("cls");
}
