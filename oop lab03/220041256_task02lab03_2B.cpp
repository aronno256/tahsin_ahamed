#include<iostream>
using namespace std;
class RationalNumber
{
    private :
       int numerator;
       int denominator;
    public :
       void assign(int n,int d)
       {
          numerator=n;
          if(d==0)
          {
             cout<<"you cannot assign 0 as denominator"<<endl;
          }
          else 
             denominator=d;
       }
       float convert()
       {
           return (float)numerator/denominator;
       }
       void invert()
       {
           if(numerator==0)
           {
               cout<<"you cannot assign 0 as denominator."<<endl;
               cout<<"inversion failed"<<endl;
           }
           else 
           {
               int swap;
               swap=numerator;
               numerator=denominator;
               denominator=swap;
           }  
       }
       void print()
       {
           cout<<"the rational number is : "<<numerator<<"/"<<denominator<<endl;
       }

};

int main()
{
    RationalNumber r,t,s;
    r.assign(2,3);
    r.invert();
    r.print();
    cout<<r.convert()<<endl;
    t.assign(2,0);
    s.assign(0,2);
    s.invert();
    s.print();
}