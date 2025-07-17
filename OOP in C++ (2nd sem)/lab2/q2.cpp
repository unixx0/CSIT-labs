/*
2. Define a class batsman with the following specifications:
Private members: bcode (4 digits code number), bname (20 characters),
innings (integer), notout (integer), runs (integer), batavg (calculated
according to the formula: batavg =runs/[innings-notout]), calcavg() –
Function to compute batavg
Public members: readdata() – Function to accept value from bcode, name,
innings, notout and invoke the function and displaydata() – Function  to
display the data members on the screen.
*/
#include <iostream>
using namespace std;
class batsman
{
private:
    int bcode;
    char bname[20];
    int innings, notout, runs;
    float batavg;
    float calcavg()
    {
        return (runs / (innings - notout));
    }

public:
    void readdata()
    {
        cout << "Enter batsman 4 digit code.no: ";
        cin >> bcode;
        cout << "Enter name: ";
        cin >> bname;
        cout << "Enter innings, notout, run" << endl;
        cin >> innings >> notout >> runs;
        batavg = calcavg();
    }
    void displaydata()
    {
        cout << "Name of batsman is" << bname << endl;
        cout << "Batsman code is " << bcode << endl;
        cout << "Batsman average is " << batavg << endl;
    }
};

int main()
{
    batsman b1;
    b1.readdata();
    b1.displaydata();
    return 0;
}