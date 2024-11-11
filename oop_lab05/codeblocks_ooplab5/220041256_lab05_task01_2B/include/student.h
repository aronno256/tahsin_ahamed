#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
using namespace std;

class student
{
    private:
    string name;
    string dept;
    string prog;
    string sec;
    int ad_year;
    string address;
    double gpa;
    string id;
    public:
    student();
    student(string n,string d,string p,string s,int a,string add,double _gpa=0.0);
    string getname()const;
    void setname(string);

    string getdept()const;
    void setdept(string);

    string getprog()const;
    void setprog(string);

    string getsec()const;
    void setsec(string);

    int get_admissionyear()const;
    void set_admissionyear(int);

    string getaddress()const;
    void setaddress(string);

    double getgpa()const;
    void setgpa(double);

    void setid(string);

    string get_studentid()const;

    double calculateGPA(double quizzes[], double midterm, double finals, double attendance);
    //void generaterandomgpa();

    void generateid();

    //void generaterandom_name();
    //void generaterandom_address();
    //void generaterandom_adyear();
};

#endif
