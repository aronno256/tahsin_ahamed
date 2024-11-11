#include<iostream>
#include<cstring>
using namespace std;
class medicine
{  
    private:
       char trade[30];
       char generic[30];
       double unit_price;
       double percentage;
    public:
       medicine()
       {
         unit_price=0;
       }
       void assignName(char name[], char genericname[])
       {
           strcpy(trade,name);
           strcpy(generic,genericname);
       }
       void assignPrice(double price)
       {
          if(price<0)
             cout<<"price cannot be negative"<<endl;
          else
             unit_price= price;  
       }
       void setdiscountpercentage(double percent)
       {
           percentage=percent;
       }
       double getSellingprice(int nos)
       {
          double sellat = (double)nos*(unit_price-((unit_price*percentage)/100));
          return sellat;
       }
       double getSellingprice()
       {
          double sellat = unit_price-((unit_price*percentage)/100);
          return sellat;
       }
       void display()
       {
          cout<<"MRP. of "<<trade<<" is BDT "<<unit_price<<".";
          cout<<" Current discount "<<percentage<<"%"<<endl;
          cout<<"Selling price BDT "<<getSellingprice();
       }

};
int main(){
    medicine m;
    m.assignName("napa","ttt");
    m.assignPrice(1.00);
    m.setdiscountpercentage(10);
    m.getSellingprice(10);
    m.display();
}