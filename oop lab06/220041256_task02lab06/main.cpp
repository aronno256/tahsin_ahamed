#include <iostream>
#include<Coordinate.h>
#include<cstdlib>
#include<ctime>
using namespace std;

void randomAssignment(Coordinate c[], int size)
{
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation
    for (int i = 0; i < size; i++)
    {
        float x = static_cast<float>(rand() % 100);  // Random number between 0 and 99
        float y = static_cast<float>(rand() % 100);  // Random number between 0 and 99
        c[i] = Coordinate(x, y);  // Assign random values to each Coordinate object
    }
}

void highest(Coordinate c[],int size)
{
    float max=c[0].getDistance();
    int index=0;
    for(int i=1;i<size;i++)
    {
        if(c[i].getDistance()>max){
            max=c[i].getDistance();
            index=i;
        }
    }
    cout<<"highest distance is "<<max<<endl;
    cout<<"of coordinate c["<<index<<"]"<<endl;
}



int main()
    {
        Coordinate coord[10];
        randomAssignment(coord,10);
        highest(coord,10);
        //lowest(coord,10);
    }

    /*
    Coordinate A(2,3);
    Coordinate B(5,6);
    cout<<A.getDistance()<<endl;
    cout<<B-A<<endl;
    */

