#include<iostream>
using namespace std;
int main(){
    int num1, num2, num3, largest;

    cout<<"Enter 3 numbers: ";
    cin>>num1>>num2>>num3;
    largest= (num1>num2)?(num1>num3?num1:num3):(num2>num3 ? num2:num3);
    cout<<"Largest number is "<<largest;
    return 0;
}
