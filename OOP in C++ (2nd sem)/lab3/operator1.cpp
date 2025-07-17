//program to overload both unary operators(increment and decrement)
#include<iostream>
using namespace std;
class Number
{
	int num;
	public:
		void setdata(int n)
		{
			num=n;
		}
		void showdata()
		{
			cout<<"The given value is "<<num<<endl;
		}
		void operator ++()
		{
			++num;
		}
		void display1()
		{
			cout<<"Incremented value is "<<num<<endl;
		}
		void operator --()
		{
			--num;
		}
		void display2()
		{
			cout<<"Again, decremented value is "<<num<<endl;
		}
};
int main()
{
	Number n;
	n.setdata(6);
	n.showdata();
	++n;
	n.display1();
	--n;
	n.display2();
	return 0;
}