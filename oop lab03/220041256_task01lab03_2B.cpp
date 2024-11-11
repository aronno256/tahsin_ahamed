#include<iostream>
using namespace std;
class counter
{
    private:
       int currentcount;
       int incre_step;
    public:
       counter();
       void SetIncrementStep(int i);
       int getCount();
       void increment();
       void resetCount();
};
counter::counter()
{
    currentcount=0;
}

void counter :: SetIncrementStep(int i)
{   
    incre_step=i;   
}
int counter :: getCount()
{
    return currentcount;
}
void counter :: increment()
{
    currentcount+=incre_step;
}
void counter :: resetCount()
{
    currentcount=0;
}

int main()
{
    counter b;
    cout<<b.getCount()<<endl;
    b.SetIncrementStep(3);
    b.increment();
    cout<<b.getCount()<<endl;
    b.resetCount();
    cout<<b.getCount()<<endl;
    b.SetIncrementStep(10);
    b.increment();
    cout<<b.getCount()<<endl;


}