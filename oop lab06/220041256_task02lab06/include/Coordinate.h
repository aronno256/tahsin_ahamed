#ifndef COORDINATE_H
#define COORDINATE_H


class Coordinate
{
private:
    float abscissa;
    float ordinate;

public:
    Coordinate();
     Coordinate(float ab,float ord);
    ~Coordinate();
    void display();

    float operator - (const Coordinate &c)const;

    float getDistance()const;
    void move_x(float val);
    void move_y(float val);
    void move(float x_val, float y_val);
    bool operator>(const Coordinate &c)const;
    bool operator<(const Coordinate &c)const;
    bool operator>=(const Coordinate &c)const;
    bool operator<=(const Coordinate &c)const;
    bool operator==(const Coordinate &c)const;
    bool operator!=(const Coordinate &c)const;

};

#endif // COORDINATE_H
