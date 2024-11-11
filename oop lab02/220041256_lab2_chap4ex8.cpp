#include<iostream>
using namespace std;

struct fraction
{
    int numerator;
    int denominator;
};
int main(){
    fraction f1,f2,sum;
    int a,b,c,d,r1,r2;
    char ch;
    cin>>a>>ch>>b;
    cin>>c>>ch>>d;
    f1.numerator=a;
    f1.denominator=b;
    f2.numerator=c;
    f2.denominator=d;
    r1=(a*d+b*c);
    r2=b*d;
    sum.numerator=r1;
    sum.denominator=r2;
    cout<<r1<<ch<<r2<<endl;

}