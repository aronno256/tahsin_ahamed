#include<iostream>
using namespace std;
class farenheit;
class kelvin;
class celsius
{
    private:
    double temp;
    public:
    celsius():temp(0.0)
    {}
    celsius(double t)
    {
        if(t < -273.15)
            cout<<"temparature cannot be less than -273.15 celsius"<<endl;
        else
            temp=t;

    }
    void assign(double t)
    {
        if(t < -273.15)
            cout<<"temparature cannot be less than -273.15 celsius"<<endl;
        else
            temp=t;    
    }
    void display()
    {
        cout<<temp<<" in celsius"<<endl;
    }
    double gettemparature()
    {
        return temp;
    }
    operator farenheit() const;
    operator kelvin() const;

};
class farenheit
{
    private:
    double temp;
    public:
    farenheit():temp(32.0)
    {}
    farenheit(double t)
    {
        if(t < -469.67)
            cout<<"temparature cannot be less than -469.67 farenheit"<<endl;
        else
            temp=t; 
    }
    void assign(double t)
    {
        if(t < -469.67)
            cout<<"temparature cannot be less than -469.67 farenheit"<<endl;
        else
            temp=t;    
    }
    void display()
    {
        cout<<temp<<" in farhenheit"<<endl;
    }
    double gettemparature()
    {
        return temp;
    }
    operator celsius() const;
    operator kelvin() const;

};
class kelvin
{
    private:
    double temp;
    public:
    kelvin():temp(273.15)
    {}
    kelvin(double t)
    {
        if(t < 0.0)
            cout<<"temparature cannot be less than 0.0 kelvin"<<endl;
        else
            temp=t; 

    }
    void assign(double t)
    {
        if(t < 0.0)
            cout<<"temparature cannot be less than 0.0 kelvin"<<endl;
        else
            temp=t;    
    }
    void display()
    {
        cout<<temp<<" in kelvin"<<endl;
    }
    double gettemparature()
    {
        return temp;
    }
    operator celsius() const
    {
        return celsius(temp-273.15);
    }
    operator farenheit() const {
        return farenheit((temp - 273.15) * 9.0 / 5.0 + 32);
    }

};

celsius::operator farenheit() const
{
    return farenheit(temp * 9.0 / 5.0 + 32);
}
celsius::operator kelvin() const {
    return kelvin(temp + 273.15);
}
farenheit::operator celsius() const
{
    return celsius((temp - 32) * 5.0 / 9.0);
}
farenheit::operator kelvin() const
{
    return kelvin((temp - 32) * 5.0 / 9.0 + 273.15);
}

int main() {
    celsius tempC;
    tempC.assign(25.0);
    tempC.display();

    farenheit tempF = tempC; 
    tempF.display();

    kelvin tempK = tempC;  
    tempK.display();
    celsius newTempC = tempF;  
    newTempC.display();
    return 0;
}