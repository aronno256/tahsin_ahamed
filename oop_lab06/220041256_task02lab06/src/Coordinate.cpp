#include "Coordinate.h"
#include<cmath>

Coordinate::Coordinate():abscissa(0.0),ordinate(0.0){};
Coordinate::Coordinate(float ab, float ord):
    abscissa(ab),ordinate(ord)
    {}
    Coordinate::~Coordinate(){}

    void Coordinate::move_x(float val)
    {
        abscissa+=val;
    }
    void Coordinate::move_y(float val)
    {
        ordinate+=val;
    }
    void Coordinate::move(float x_val,float y_val)
    {
        abscissa+=x_val;
        ordinate+=y_val;
    }

    float Coordinate::getDistance()const
    {
        return sqrt(abscissa * abscissa + ordinate * ordinate);
    }
    float Coordinate::operator-(const Coordinate &c)const
    {
        return sqrt(((abscissa - c.abscissa)*(abscissa - c.abscissa)) + ((ordinate -c.ordinate)*(ordinate -c.ordinate)));
    }

    bool Coordinate::operator<(const Coordinate &c)const
    {
        return (getDistance() < c.getDistance());
    }
    bool Coordinate::operator>(const Coordinate &c)const
    {
        return (getDistance() > c.getDistance());
    }
    bool Coordinate::operator<=(const Coordinate &c)const
    {
        return (getDistance() <= c.getDistance());
    }
    bool Coordinate::operator>=(const Coordinate &c)const
    {
        return (getDistance() >= c.getDistance());
    }
    bool Coordinate::operator==(const Coordinate &c)const
    {
        return (getDistance() == c.getDistance());
    }
    bool Coordinate::operator!=(const Coordinate &c)const
    {
        return (getDistance() != c.getDistance());
    }



