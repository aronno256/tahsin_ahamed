#include<iostream>
using namespace std;
enum etype{laborer,secretary,manager,accountant,executive,researcher};
int main(){
    etype fl;
    char ch;
    cout<< "enter employee type :";
    cin>>ch;
    switch(ch){
        case 'l':fl=laborer;
                break;
        case 's':fl=secretary;
                break;
        case 'm':fl=manager;
                break;
        case 'a':fl=accountant;
                break;
        case 'e':fl=executive;
                break;
        case 'r':fl=researcher;
                break;
    }
    cout<<"employee type is ";
    switch(fl){
        case laborer : cout<<"laborer";
                       break;
        case secretary: cout<<"secretary";
                       break;
        case manager: cout<< "manager";
                        break;
        case accountant: cout<< "accountant";
                        break;
        case executive:cout<<"executive";
                        break;
        case researcher:cout<<"researcher";
                        break;
    }       

}