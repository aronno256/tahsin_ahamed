#include"student.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int randomInRange(int min, int max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    return rand() % (max - min + 1) + min;
}


student::student():gpa(0.0)
{}
//student::student(string n,string d,string p,string s,int a,string add,int _gpa=0.0):name(n),dept(d),sec(s),prog(p),ad_year(a),address(add),gpa(_gpa)
//{}

string student::getname()const
{
    return name;
}

void student::setname(string n)
{
    name=n;
}
string student::getdept()const{
    return dept;
}

void student::setdept(string d)
{
    dept=d;
}
string student::getprog()const
{
    return prog;
}
void student::setprog(string p)
{
    prog=p;
}

string student:: getsec()const
{
    return sec;
}
void student ::setsec(string s)
{
    sec=s;
}
int student:: get_admissionyear()const
{
    return ad_year;
}
void student::set_admissionyear(int a)
{
    ad_year=a;
}
string student::getaddress()const
{
    return address;
}
void student::setaddress(string add)
{
    address=add;
}
double student::getgpa()const
{
    return gpa;
}
void student::setgpa(double g)
{
     gpa=g;
}
string student::get_studentid()const
{
    return id;
}

string student::generateid()
{
    string s_id;
    string year=to_string(ad_year);
    s_id=year[2]+year[3];
    id+="00";
    if(dept=="CSE")
    {
        id+="4";
        if(prog=="CSE")
           id+="1";
        else if(prog=="SWE")
           id+="2";
    }
    
    id+=sec;
    id+=to_string(randomInRange(1,60));
    
    return s_id;

}