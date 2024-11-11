#include<iostream>
#include<string>
using namespace std;

class Account
{
    private : 

    string accountNo;
    string accountName;
    float balance;

    public:

    Account(string ac_name, float b) 
    : accountName(ac_name),balance(b) {}
    void set_account_name(const string& ac_name)
    {
        accountName=ac_name;
    }
    string get_account_name() const
    {
        return accountName;
    }
    void set_account_no(const string& ac_no)
    {
        accountNo=ac_no;
    }
    string get_account_no() const
    {
        return accountNo;
    }
    void set_balance(float b)
    {
        balance=b;
    }
    float get_balance() const
    {
        return balance;
    }
};

class CurrentAccount : public Account
{
    private :
    static const int serviceCharge;
    static const string accountPrefix;
    static int nextAccount;

    public:
    CurrentAccount(string ac_name,float b) 
    : Account(ac_name,b)
    {
        set_account_no(accountPrefix+"-"+to_string(nextAccount++));
    }
    void description() const 
    {
        cout << "Current Account\nAccount No: " << get_account_no()
             << "\nAccount Name: " << get_account_name()
             << "\nBalance: " << get_balance()
             << "\nService Charge: " << serviceCharge << endl;
    }
};
const int CurrentAccount :: serviceCharge=100;
const string CurrentAccount :: accountPrefix="100";
int CurrentAccount :: nextAccount = 1;

class SavingsAccount : public Account
{
    private :
    float interestRate;
    float monthlyDepositAmount;
    static const string accountPrefix;
    static int nextAccount;

    public :
    SavingsAccount(string ac_name,float b,float ir,float mda)
    : Account(ac_name,b),interestRate(ir),monthlyDepositAmount(mda)
    {
        set_account_no(accountPrefix+"-"+to_string(nextAccount++));
    }
    void description() const
    {
        cout << "Savings Account\nAccount No: " << get_account_no()
             << "\nAccount Name: " << get_account_name()
             << "\nBalance: " << get_balance()
             << "\nInterest Rate: " << interestRate
             << "\nMonthly Deposit Amount: " << monthlyDepositAmount << endl;
    }

};
const string SavingsAccount :: accountPrefix = "200";
int SavingsAccount :: nextAccount = 1;

class LoanAccount : public Account
{
    private :
    float interestRate;
    float monthlyDepositAmount;
    static const string accountPrefix;
    static int nextAccount;

    public :
    LoanAccount(string ac_name,float b,float ir,float mda)
    : Account(ac_name,b),interestRate(ir),monthlyDepositAmount(mda)
    {
        set_account_no(accountPrefix+"-"+to_string(nextAccount++));
    }
    void description() const
    {
        cout << "Loan Account\nAccount No: " << get_account_no()
             << "\nAccount Name: " << get_account_name()
             << "\nBalance: " << get_balance()
             << "\nInterest Rate: " << interestRate
             << "\nMonthly Deposit Amount: " << monthlyDepositAmount << endl;
    }

};
const string LoanAccount :: accountPrefix = "900";
int LoanAccount :: nextAccount = 1;

class MonthlyDepositScheme : public Account
{
    private :
    float interestRate;
    float monthlyDepositAmount;
    static const string accountPrefix;
    static int nextAccount;

    public :
    MonthlyDepositScheme(string ac_name,float b,float ir,float mda)
    : Account(ac_name,b),interestRate(ir),monthlyDepositAmount(mda)
    {
        set_account_no(accountPrefix+"-"+to_string(nextAccount++));
    }
    void description() const
    {
        cout << "Monthly Deposit Scheme\nAccount No: " << get_account_no()
             << "\nAccount Name: " << get_account_name()
             << "\nBalance: " << get_balance()
             << "\nInterest Rate: " << interestRate
             << "\nMonthly Deposit Amount: " << monthlyDepositAmount << endl;
    }

};
const string MonthlyDepositScheme :: accountPrefix = "300";
int MonthlyDepositScheme :: nextAccount = 1;

class TwoYearMDS : public MonthlyDepositScheme 
{
private:
    float maximumInterest;
    static int fixedamount;

public:
    TwoYearMDS(string name, float bal, float rate, float deposit, float maxInt)
        : MonthlyDepositScheme(name, bal, rate, deposit), maximumInterest(maxInt) {}

    void description() const 
    {
        cout << "Two-Year Monthly Deposit Scheme\nAccount No: " << get_account_no()
             << "\nAccount Name: " << get_account_name()
             << "\nBalance: " << get_balance()
             << "\nMaximum Interest: " << maximumInterest
             <<"\n You need to deposit atleast "<<fixedamount<<" tk every month"<<endl;
    }
};
int TwoYearMDS :: fixedamount = 1000;

class FiveYearMDS : public MonthlyDepositScheme 
{
private:
    float maximumInterest;

public:
    FiveYearMDS(string name, float bal, float rate, float deposit, float maxInt)
        : MonthlyDepositScheme(name, bal, rate, deposit), maximumInterest(maxInt) {}

    void description() const 
    {
        cout << "Five-Year Monthly Deposit Scheme\nAccount No: " << get_account_no()
             << "\nAccount Name: " << get_account_name()
             << "\nBalance: " << get_balance()
             << "\nMaximum Interest: " << maximumInterest << endl;
    }
};

class InitialDepositMDS : public MonthlyDepositScheme 
{
private:
    float maximumInterest;
    float initialDepositAmount;

public:
    InitialDepositMDS(string name, float bal, float rate, float deposit, float maxInt, float initDep)
        : MonthlyDepositScheme(name, bal, rate, deposit), maximumInterest(maxInt), initialDepositAmount(initDep) {}

    void description() const 
    {
        cout << "Initial Deposit Monthly Deposit Scheme\nAccount No: " << get_account_no()
             << "\nAccount Name: " << get_account_name()
             << "\nBalance: " << get_balance()
             << "\nMaximum Interest: " << maximumInterest
             << "\nInitial Deposit Amount: " << initialDepositAmount << endl;
    }
};


int main()
{
    CurrentAccount currentAcc1("Jhon Cena",5000.0);
    CurrentAccount currentAcc2("Michel Jordan",10500.0);
    SavingsAccount savingsAcc1("Leonel Messi", 43000.0, 3.5, 500.0);
    SavingsAccount savingsAcc2("Neymar jr", 7000.0, 3.5, 500.0);
    MonthlyDepositScheme monthlyDeposit("Al Sendro", 1500.0, 4.0, 300.0);
    LoanAccount loanAcc("Alister cook", 10000.0, 5.0, 1000.0);
    TwoYearMDS twoYearMDS("Bob Marley", 2500.0, 4.5, 350.0, 10.0);
    FiveYearMDS fiveYearMDS("Snoop Dog", 5000.0, 5.5, 500.0, 15.0);
    InitialDepositMDS initDepMDS("Big E", 3000.0, 6.0, 400.0, 20.0, 1000.0);

    currentAcc1.description();
    cout << endl;
    currentAcc2.description();
    cout << endl;
    savingsAcc1.description();
    cout << endl;
    savingsAcc2.description();
    cout << endl;
    monthlyDeposit.description();
    cout << endl;
    loanAcc.description();
    cout << endl;
    twoYearMDS.description();
    cout << endl;
    fiveYearMDS.description();
    cout << endl;
    initDepMDS.description();

}










