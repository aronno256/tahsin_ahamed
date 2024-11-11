#include"student.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
    student s;
    s.setname("aronno");
    s.set_admissionyear(2022);
    s.setdept("CSE");
    s.setprog("CSE");
    s.setsec("2");

    cout<<s.generateid()<<endl;
}
