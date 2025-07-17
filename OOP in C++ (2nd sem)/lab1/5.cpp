#include<iostream>
using namespace std;
int main(){
    float principal, rate, time, si;
    cout<<"Enter Principal, Time(in years) and Rate respectively: ";
    cin>>principal>>rate>>time;
    si=(principal*rate*time)*0.01;
    cout<<si<<" is the required Simple Interest";
    return 0;
}