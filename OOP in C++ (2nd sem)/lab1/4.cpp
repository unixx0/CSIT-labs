#include<iostream>
using namespace std;
int main(){
    float far, centi;

    cout<<"Enter the temperature in Fahrenheit: ";
    cin>>far;
    centi= (far-32)*0.5556;
    cout<<"The tempreature in centegrade is: "<<centi;
}