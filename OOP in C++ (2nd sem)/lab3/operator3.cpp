//program to overload binary operator + to add two complex numbers by friend function
#include<iostream>
using namespace std;
class Complex
{
	int real,img;
	public:
		void setdata(int r,int i)
		{
			real=r;
			img=i;
		}
		void showdata()
		{
			cout<<"The complex number is "<<real<<" + "<<img<<"i"<<endl;
		}
		void display()
		{
			cout<<"The sum is "<<real<<" + "<<img<<"i"<<endl;
		}
		friend Complex operator +(Complex &obj1,Complex &obj2);
};
Complex operator +(Complex &o1,Complex &o2)
		{
			Complex c;
			c.real=o1.real+o2.real;
			c.img=o1.img+o2.img;
			return c;
		}
int main()
{
	Complex c1,c2,c3;
	c1.setdata(5,3);
	c2.setdata(9,8);
	c1.showdata();
	c2.showdata();
	c3=c1 + c2;
	c3.display();
	return 0;
}