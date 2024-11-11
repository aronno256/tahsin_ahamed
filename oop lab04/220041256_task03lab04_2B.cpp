#include<iostream>
using namespace std;

class employee
{
    private :
    string EmpName;
    int ID;
    int Age;
    float Salary;
    string getStatus()
    {
        if(Age<26)
        {
            if(Salary<20001)
                return "Low salaried person";
            else 
                return "Moderate salaried person";
        }
        else
        {
            if(Salary<21001)
                return "Low salaried person";
            else if(Salary<60001)
               return "Moderate salaried person";
            else
               return "High salaried person";       
        }
    }

    public:
    void FeedInfo()
    {
        cout<<"EmpName : ";
        cin>>EmpName;
        cout<<"ID : ";
        cin>>ID;
        cout<<"Age : ";
        cin>>Age;
        cout<<"Salary : ";
        cin>>Salary;
    }

    void showinfo()
    {
        cout << "\nEmployee Information: "<<endl;
        cout << "Name: " << EmpName << endl;
        cout << "ID: " << ID << endl;
        cout << "Age: " << Age << endl;
        cout << "Salary: " << Salary << endl;
        cout << "Status: " << getStatus() << endl;

    }
};

int main()
{
    employee e;
    e.FeedInfo();
    e.showinfo();


}