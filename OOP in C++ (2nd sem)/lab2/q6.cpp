/*
6. Define a class REPORT with the following specification: 
Private members: adno (4 digits admission number), name (20 characters), 
marks (an array of 5 floating point values), average (average marks 
obtained), GETAVG() (a function to compute the average obtained in five 
subject) 
Public members: READINFO() – function to accept values for adno, name, 
marks. Invoke the function GETAVG() and DISPLAYINFO() – function to 
display all data members of report on the screen. You should give function 
definitions. 

*/
#include<iostream>
using namespace std;
class REPORT{
    private:
 int adno;
 char name[20];
  float marks[5],average;
  float GETAVG(){
    int sum=0,i;
    for(i=0;i<5;i++){
     sum = sum + marks[i];
    }
    return sum/5.0;
  
  }
  public:
  void READINFO();
  void DISPLAYINFO();
};
 
 void REPORT::READINFO()
  {
    int avg,i;
     do{
      cout<<"Enter admission number"<<endl;
      cin>>adno;
     }while(adno<999 || adno>10000);
     
    cout<<"Enter Name: "<<endl;
    cin>>name;
    cout<<"Enter marks in 5 subject"<<endl;
    for(int i=0;i<5;i++)
    {
     cin>>marks[i];
    }
    average = GETAVG(); 
  }
  
  void REPORT::DISPLAYINFO()
  {
    cout<<"Admission number: "<<adno<<endl<<"Name: "<<name<<endl<<"Average: "<<average;
  }
 int main()
{
 REPORT r1;
 r1.READINFO();
 r1.DISPLAYINFO(); 
 return 0;
}