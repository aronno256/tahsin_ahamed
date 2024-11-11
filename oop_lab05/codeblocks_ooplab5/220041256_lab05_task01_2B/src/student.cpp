#include"student.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int RANDOMInRange(int min, int max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    return rand() % (max - min + 1) + min;
}


student::student():gpa(0.0)
{}
student::student(string n,string d,string p,string s,int a,string add,double _gpa):
    name(n),dept(d),sec(s),prog(p),ad_year(a),address(add),gpa(0.0)
    {}

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

void student :: setid(string ID)
{
    id=ID;
}


void student::generateid()
{
    string s_id="";
    string year=to_string(ad_year);
    s_id+=year[2];
    s_id+=year[3];
    s_id+="00";
    if(dept=="CSE")
    {
        s_id+="4";
        if(prog=="CSE")
           s_id+="1";
        else if(prog=="SWE")
           s_id+="2";
    }

    s_id+=sec;
    s_id+=to_string(RANDOMInRange(1,60));

    id=s_id;

}

double student :: calculateGPA(double quizzes[], double midterm, double finals, double attendance)
{
    double quizTotal=0;
    double totalMarks=0;
    for (int i = 0; i < 4; i++) {
        quizTotal += quizzes[i];
    }

    totalMarks = quizTotal + midterm + finals + attendance;
    if (totalMarks >= 90)
        gpa = 4.0;
    else if (totalMarks >= 80)
        gpa = 3.5;
    else if (totalMarks >= 70)
        gpa = 3.0;
    else if (totalMarks >= 60)
        gpa = 2.5;
    else if (totalMarks >= 50)
        gpa = 2.0;
    else
        gpa = 0.0;
    return gpa;

}
/*
void student:: generaterandomgpa()
{
    double quizzes[4];
    double midterm;
    double finals;
    double attendance;
    quizzes[1]=randomInRange(1,5);
    quizzes[2]=randomInRange(1,5);
    quizzes[3]=randomInRange(1,5);
    quizzes[4]=randomInRange(1,5);
    midterm=randomInRange(1,25);
    finals=randomInRange(1,50);
    attendance=randomInRange(1,5);
    calculateGPA(quizzes, midterm, finals, attendance);

}

*/
/*
void student :: generaterandom_name()
{
    string firstname=generateRandomString(4);
    string lastname=generateRandomString(4);
    name=firstname+" "+lastname;
}
void student :: generaterandom_adyear()
{
    ad_year=randomInRange(2020,2023);
}
void student :: generaterandom_address()
{
    address=generateRandomString(4)+" "+generateRandomString(4)+" "+generateRandomString(4)+" "+generateRandomString(4)+" "+generateRandomString(4);

}

*/
