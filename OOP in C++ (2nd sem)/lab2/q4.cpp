/*
4. Define a class in C++ with following description:
Private Members: A data member Flight number of type integer, A data
member Destination of type string, A data member Distance of type float, A
data member Fuel of type float, A member function CALFUEL() to calculate
the value of Fuel as per the following criteria
Distance                             Fuel
<=1000                                500
more than 1000  and <=2000            1100
more than 2000                         2200
Public Members: A function FEEDINFO() to allow user to enter values for
Flight Number, Destination, Distance & call function CALFUEL() to
calculate the quantity of Fuel and A function SHOWINFO() to allow user to
view the content of all the data members.
*/
#include <iostream>
using namespace std;
class plane
{
private:
    int flight_no;
    char Destination[25];
    float Distance, Fuel;
    int CALFUEL()
    {
        if (Distance <= 1000)
        {
            return 500;
        }
        else if (Distance > 1000 && Distance <= 2000)
        {
            return 1100;
        }
        else if (Distance > 2000)
        {
            return 2200;
        }
    }

public:
    void FEEDINFO()
    {
        cout << "Enter Flight.no, Distination and Distance" << endl;
        cin >> flight_no >> Destination >> Distance;
        Fuel = CALFUEL();
    }
    void SHOWINFO()
    {
        cout << "Flight.No: " << flight_no << endl
             << "Distination: " << Destination << endl;
        cout << "Distance: " << Distance << endl
             << "Fuel: " << Fuel;
    }
};

int main()
{
    plane f1;
    f1.FEEDINFO();
    f1.SHOWINFO();
    return 0;
}