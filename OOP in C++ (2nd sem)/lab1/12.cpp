#include<iostream>
using namespace std;
int main(){

    int money, num500, num100, num50, num20, num10, num5, num1;
    cout<<"Enter the integral value: ";
    cin>>money;
    num500= money/500;
    cout<<"500:  "<<num500<<endl;
    num100= (money-500*num500)/100;
    cout<<"100:  "<<num100<<endl;
     num50= (money-500*num500-100*num100)/50;
    cout<< "50:   "<<num50<<endl;
     num20= (money-500*num500-100*num100-50*num50)/20;
    cout<< "20:   "<<num20<<endl;
     num10= (money-500*num500-100*num100-50*num50-20*num20)/10;
    cout<< "10:   "<<num10<<endl;
     num5= (money-500*num500-100*num100-50*num50-20*num20-10*num10)/5;
    cout<< "5:    "<<num5<<endl;
     num1= (money-500*num500-100*num100-50*num50-20*num20-10*num10-5*num5)/1;
    cout<< "1:    "<<num1<<endl;
    return 0;
    

}