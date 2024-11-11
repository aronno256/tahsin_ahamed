#include <iostream>
#include<Matrix3D.h>
using namespace std;

int main()
{
    double a[3][3]={
    {1,0,5},
    {2,1,6},
    {3,4,0}
    };
    double b[3][3]={
    {2,2,2},
    {3,3,3},
    {4,4,4}
    };

    Matrix3D A(a,1);
    Matrix3D B(b,3);
    A.getMatrix();
    B.getMatrix();
    //A.increment();
    B.increment();
    A.getMatrix();
    B.getMatrix();
    Matrix3D C;
    C=A.inverse();
    C.getMatrix();

    Matrix3D D;
    D=A-B;
    D.getMatrix();

    if(A==B)
        cout<<"A==B"<<endl;
    else
        cout<<"A!=B"<<endl;




}
