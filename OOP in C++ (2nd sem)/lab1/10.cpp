#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    (num%2==0)?cout<<"It is even" : cout<<"It is odd";
    return 0;
}