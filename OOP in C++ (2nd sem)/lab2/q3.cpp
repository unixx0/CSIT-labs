/*  3. Define a class TEST in C++ with following description:
Private Members: TestCode (of type integer),
Description (of type string), NoCandidate (of type integer), CenterReqd (of type integer), a member function CALCNTR()
to calculate and return the number of centers as (NoCandidates/100+1)
Public Members: A function SCHEDULE() to allow
 user to enter values for TestCode, Description, NoCandidate & call function CALCNTR() to calculate the number
 of Centres A function DISPTEST() to allow user to view the content of all the data members

*/

#include <iostream>
using namespace std;
class TEST
{
private:
    int TestCode, NoCandidate, Centerread;
    char Description[100];
    int CALCNTR()
    {
        return (NoCandidate / 100 + 1);
    }

public:
    void SCHEDULE()
    {
        cout << "Enter value for TestCode, Description, NoCandidate: " << endl;
        cin >> TestCode >> Description >> NoCandidate;
        Centerread = CALCNTR();
    }
    void DISPTEST()
    {
        cout << "The testcode is " << TestCode << endl;
        cout << "Given discription is " << Description << endl;
        cout << "The number of centers are: " << Centerread;
    }
};

int main()
{
    TEST t1;
    t1.SCHEDULE();
    t1.DISPTEST();
    return 0;
}