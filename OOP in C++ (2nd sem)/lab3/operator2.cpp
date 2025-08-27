//program to overload binary operator + to add two complex numbers
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
		Complex operator +(Complex &obj)
		{
			Complex c;
			c.real=real+obj.real;
			c.img=img+obj.img;
			return c;
		}
		void display()
		{
			cout<<"The sum is "<<real<<" + "<<img<<"i"<<endl;
		}
};
int main()
{
	Complex c1,c2,c3;
	c1.setdata(3,7);
	c2.setdata(4,2);
	c1.showdata();
	c2.showdata();
	c3=c1 + c2;
	c3.display();
	return 0;
}