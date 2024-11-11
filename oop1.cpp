#include<iostream>
#include<string>
using namespace std;
class binary
{
    private:
      string s;
      void check_bin(void);
    public:
      void read_bin(void);
      void ones_com(void);
      void display(void);  
};
void binary :: read_bin(void)
{
    cout<<"enter a binary num :";
    cin>>s;
    check_bin();
}
void binary :: check_bin(void)
{
    for(int i=0; i<s.length(); i++)
    {
        if(s.at(i)!='0' && s.at(i)!='1')
        {
            cout<<"incorrect binary format"<<endl;
            exit(0);
        }
    }
}
void binary :: ones_com()
{
        for(int i=0; i<s.length(); i++)
    {
        if(s.at(i)=='0')
           s.at(i)='1';
        else
           s.at(i)='0';
    }
}
void binary :: display(void)
{
    for(int i=0; i<s.length(); i++)
    {
       cout<<s.at(i);
    }
    cout<<endl;
}

int main()
{
    binary b;
    b.read_bin();
    b.display();
    b.ones_com();
    b.display();

}