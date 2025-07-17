#include<iostream>
using namespace std;
int main (){
    int year, month, days, day;
    cout<<"Enter the number of days: ";
    cin>>days;
    year=days/365;
    month= (days-year*365)/30;
    day= days-(year*365)-(month*30);
    cout<<year<<" year "<<month<< " month "<<day<<" day";
    return 0;


}