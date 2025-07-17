#include<iostream>
using namespace std;
int main(){
    int num;
    string c;
    cout<<"Enter the number: ";
    cin>>num;
   c=(num>=0)?"It is positive":"It is Negative";
   cout<<c;
   return 0;
}