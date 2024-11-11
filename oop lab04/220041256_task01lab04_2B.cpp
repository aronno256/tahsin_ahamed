#include<iostream>
#include<cmath>
using namespace std;

class calculator
{
    private :
    float currentstatus;
    float prevstatus;
    void setcurrentstatus(float x) 
    {
        prevstatus=currentstatus;
        currentstatus=x;
    }    
    float getcurrentstatus()
    {
        return currentstatus;
    }
    float  getpreviousstatus()
    {
        return prevstatus;
    }
    public :
    calculator()
    {
        setcurrentstatus(0);
    }
    
    calculator(float x)
    {
        setcurrentstatus(x);
    }
    
    
    float calculatesine()
    {
        float angle=((getcurrentstatus())*3.1416)/180;
        return sin(angle);
    }
    float calculatecos()
    {
        float angle=((getcurrentstatus())*3.1416)/180;
        return cos(angle);
    }
    float calculatetangent()
    {
        if(getcurrentstatus()==90)
        {
            cout<<"invalid operation : undefined class"<<endl;
            setcurrentstatus(getpreviousstatus());
        }
        else
        {
            float angle=((getcurrentstatus())*3.1416)/180;
            return tan(angle);
        }
    }
    float calculatearcsine()
    {
        float sinevalue=calculatesine();
        if(sinevalue<-1 || sinevalue>1)
        {
            cout<<"invalid operation : undefined result"<<endl;
        }
        else
           return asin(sinevalue);
    }
    float calculatearccosine()
    {
        float cosvalue=calculatecos();
        if(cosvalue<-1 || cosvalue>1)
        {
            cout<<"invalid operation : undefined result"<<endl;
        }
        else
           return acos(cosvalue);
    }
    float calculatearctangent()
    {
        float tanvalue=calculatetangent();
           return atan(tanvalue);
    }
    void calculateforangle(float paramangle)
    {
        float angle=(paramangle*3.1416)/180;
        cout<<"sin :"<<paramangle<<sin(angle)<<endl;
        cout<<"cos :"<<paramangle<<cos(angle)<<endl;
        if(angle==90)
        {
            cout<<"invalid operation : undefined result"<<endl;
        }
        else{
            cout<<"tan :"<<paramangle<<tan(angle);
        }
    }    
    void clear()
    {
        setcurrentstatus(0);
    }
    void display()
    {
        cout<<getcurrentstatus()<<endl;

    }
    ~calculator()
    {
        cout<<"calculator display : "<<getcurrentstatus()<<endl;
        cout<<"Destructor of the  calculator object is called"<<endl;
    }
      
};

int main()
{
    calculator calc(270);
    cout<<calc.calculatesine()<<endl;
    cout<<calc.calculatearccosine()<<endl;
    cout<<calc.calculatetangent()<<endl;
    cout<<calc.calculatearctangent()<<endl;
    calc.display();

}