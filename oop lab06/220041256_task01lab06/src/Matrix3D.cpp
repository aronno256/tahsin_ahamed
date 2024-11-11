#include<iostream>
#include "Matrix3D.h"
using namespace std;

Matrix3D::Matrix3D()
{
    incre=1;
    count=0;
}
Matrix3D::Matrix3D(double mat[3][3], int increment=1)
{
    incre=(increment > 0) ? increment : 1;
    count=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            matrix[i][j]=mat[i][j];
        }
    }
}
Matrix3D::~Matrix3D()
{
    //dtor
}

void Matrix3D::setIncrement(int val)
{
    if(count ==0 && val > -1)
        incre=val;
    else if(count != 0)
        cout<<"it cannot set the increment step"<<endl;
}
int Matrix3D::getMatrix() const
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
double Matrix3D::det()const
{
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
         - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
         + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

Matrix3D Matrix3D::inverse()const
{
    double determinant = det();
    if (determinant == 0)
    {
        throw runtime_error("Singular Matrix");
    }
    double inv[3][3];
    inv[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) / determinant;
    inv[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) / determinant;
    inv[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) / determinant;
    inv[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) / determinant;
    inv[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) / determinant;
    inv[1][2] = (matrix[1][0] * matrix[0][2] - matrix[0][0] * matrix[1][2]) / determinant;
    inv[2][0] = (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]) / determinant;
    inv[2][1] = (matrix[2][0] * matrix[0][1] - matrix[0][0] * matrix[2][1]) / determinant;
    inv[2][2] = (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]) / determinant;
    return Matrix3D(inv);

}
void Matrix3D::increment()
{
    for(int i=0;i <3; i++)
    {
        for(int j=0; j<3; j++)
        {
            matrix[i][j]+=static_cast<double>(incre);
        }
    }
}

Matrix3D Matrix3D::operator+(const Matrix3D &a)const
{
    double res[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            res[i][j]=matrix[i][j]+ a.matrix[i][j];
        }
    }
    return Matrix3D(res);
}

Matrix3D Matrix3D::operator-(const Matrix3D &a)const
{
    double res[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            res[i][j]=matrix[i][j]- a.matrix[i][j];
        }
    }
    return Matrix3D(res);
}

Matrix3D Matrix3D ::operator*(const Matrix3D &a) const
{
    double res[3][3] = {0};
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                res[i][j] += matrix[i][k] * a.matrix[k][j];
            }
        }
    }
    return Matrix3D(res);
}

bool Matrix3D::operator>(const Matrix3D &a)const
{
    return det()>a.det();
}

bool Matrix3D::operator<(const Matrix3D &a)const
{
    return (det()<a.det());
}
bool Matrix3D::operator>=(const Matrix3D &a)const
{
    return (det()>=a.det());
}

bool Matrix3D::operator<=(const Matrix3D &a)const
{
    return (det()<=a.det());
}

bool Matrix3D::operator==(const Matrix3D &a)const
{
    bool t=true;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(matrix[i][j]!= a.matrix[i][j])
                t=false;
        }
    }
    return t;
}

bool Matrix3D::operator!=(const Matrix3D &a)const
{
    int c=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(matrix[i][j]== a.matrix[i][j])
                c++;
        }
    }
    return (c==9) ?  false : true;
}














