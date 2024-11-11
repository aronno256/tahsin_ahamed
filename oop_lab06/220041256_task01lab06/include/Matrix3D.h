#ifndef MATRIX3D_H
#define MATRIX3D_H


class Matrix3D
{
private:
    double matrix[3][3];
    int incre;
    int count;
public:

    Matrix3D();
    Matrix3D(double mat[3][3],int increment);
    ~Matrix3D();
    double det()const;
    Matrix3D inverse()const;
    void setIncrement(int);
    int getMatrix()const;
    void increment();
    Matrix3D operator+(const Matrix3D &) const;
    Matrix3D operator-(const Matrix3D &) const;
    Matrix3D operator*(const Matrix3D &) const;
    bool operator>(const Matrix3D &)const;
    bool operator<(const Matrix3D &)const;
    bool operator>=(const Matrix3D &)const;
    bool operator<=(const Matrix3D &)const;
    bool operator==(const Matrix3D &)const;
    bool operator!=(const Matrix3D &)const;
};

#endif // MATRIX3D_H
