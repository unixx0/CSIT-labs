#include<iostream>
#include<stdio.h>
using namespace std;
class student{
    private:
    int admno;
    string sname;
    float english, maths, science;
    public:
    void takedata(){
        cout<<"Enter your Admission NO."<<endl;
        cin>>admno;
        cout<<"Enter your name"<<endl;
        cin>>sname;
        cout<<"Enter your marks in English, Maths and Science respectively"<<endl;
        cin>>english>>maths>>science;
        
    }
    void showdata(){
        cout<<"Admission no= "<<admno<<", Name= "<<sname<<", Marks in maths= "<<maths<<", Marks in english= "<<english<<", Marks in science= "<<science<<endl;
        
       }
    
    float ctotal(){
        return english+maths+science;
    }
    } s;
    int main(){
        s.takedata();
        s.showdata();
        cout<<"The total marks is "<<s.ctotal()<<endl;
        return 0;
    }




    


