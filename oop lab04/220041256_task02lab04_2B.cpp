#include<iostream>
using namespace std;


class BankAccount
{
    private:
    int acc_number;
    string holder_name;
    string acc_type;
    double current_balance;
    const double min_balance;
    static int total_acc;
    static int current_acc;
    static double totalsourcetax;
    
    public:
    BankAccount(int ac_num, string name, string type,double balance,double minbalance):
        acc_number(ac_num),holder_name(name),
        acc_type(type),current_balance(balance),
        min_balance(minbalance)
    {
        total_acc++;
        current_acc++;
    }
    ~BankAccount()
    {
        cout<<"Account of "<<holder_name<<" with account no "<<acc_number<<" is destroyed with a balance BDT "<<current_balance<<endl;
        current_acc--;
    }
    
    void showBalance()
    {
        cout<<"current balance of "<<holder_name<<" is : "<<current_balance<<endl;
    }
    void show_all_info() const
    {
        cout << "Account Number: " << acc_number << endl;
        cout << "Account Holder: " << holder_name << endl;
        cout << "Account Type: " << acc_type << endl;
        cout << "Current Balance: BDT " << current_balance << endl;
        cout << "Minimum Balance: BDT " << min_balance << endl;
    }
    void deposit(double amount)
    {
        if(amount<1)
        {
            cout<<"invalid amount"<<endl;
        }
        else
        {
            current_balance+=amount;
        }
    }
    void withdrawal(double amount)
    {
        if(amount<1)
        {
            cout<<"invalid amount"<<endl;
        }
        else
        {
            current_balance-=amount;
        }
    }
    void giveInterest(int percentage=3)
    {
        double interest=current_balance*(percentage/100.0);
        double sourcetax=interest*0.1;
        interest=interest-sourcetax;
        current_balance+=interest;
        totalsourcetax+=sourcetax;
    }
    static int get_total_acc()
    {
        return total_acc;
    }
    static int get_current_acc()
    {
        return current_acc;
    }
    static int get_total_sourcetax()
    {
        return totalsourcetax;
    }
    double get_current_balance() const
    {
        return current_balance;
    }
};

int BankAccount :: total_acc=0;
int BankAccount :: current_acc=0;
double BankAccount :: totalsourcetax=0;

void display_stat()
{
    cout<<"Bank account created : "<<BankAccount::get_total_acc()<<endl;
    cout<<"Current Bank Account : "<<BankAccount::get_current_acc()<<endl;
    cout<<"Total source tax : "<<BankAccount::get_total_sourcetax()<<endl;
}

BankAccount larger(const BankAccount a, const BankAccount b)
{
    if(a.get_current_balance()>b.get_current_balance())
    {
        return a;
    }
    else return b;
}


int main()
{
    BankAccount ac1(1,"aronno","savings",5000.0,1000.0);
    BankAccount ac2(2,"shakil","current",2000.0,500.0);

    ac1.show_all_info();
    ac2.show_all_info();

    ac1.deposit(5000.0);
    ac1.giveInterest();
    ac1.showBalance();

    ac2.withdrawal(500.0);
    ac2.giveInterest(10);
    ac2.showBalance();

   // BankAccount larg=larger(ac1,ac2);
   // cout<<"account with higher balance is : "<<endl;
   // larg.show_all_info();

    display_stat();

}