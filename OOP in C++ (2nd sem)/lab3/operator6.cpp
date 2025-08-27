#include<iostream>
using namespace std;
class Fraction
{
	int numerator,denominator;
	public:
	void setdata(int n,int d )
	{
	    numerator=n;
		denominator=d;	
	}	
	void showdata()
	{
		cout<<"The given values are "<<numerator<<" / "<<denominator<<endl;
	}
	Fraction operator +(Fraction &obj)
	{
		Fraction f;
		f.numerator=numerator*obj.denominator+obj.numerator*denominator;
		f.denominator=denominator*obj.denominator;
		return f;
	}
	Fraction operator -(Fraction &obj)
	{
		Fraction f;
		f.numerator=numerator*obj.denominator-obj.numerator*denominator;
		f.denominator=denominator*obj.denominator;
		return f;
	}
	Fraction operator *(Fraction &obj)
	{
		Fraction f;
		f.numerator=numerator*obj.numerator;
		f.denominator=denominator*obj.denominator;
		return f;
	}
	Fraction operator /(Fraction &obj)
	{
		Fraction f;
		f.numerator=numerator*obj.denominator;
		f.denominator=denominator*obj.numerator;
		return f;
	}
	void operator ==(Fraction &obj)
	{ 
	    if(numerator==obj.numerator && denominator==obj.denominator)
	    {
	    	cout<<"Both fractions are equal."<<endl;
		}
		else
		{
			cout<<"Both fractions are not equal."<<endl;
		}
	}
	void display()
	{
		cout<<numerator<<" / "<<denominator<<endl;
	}
};
int main()
{
	Fraction f1,f2,f3;
	f1.setdata(3,7);
	f2.setdata(4,5);
	f1.showdata();
	f2.showdata();
	f3=f1+f2;
	cout<<endl<<"The sum of two fractions is ";
	f3.display();
	f3=f1-f2;
	cout<<"The difference of two fraction is ";
	f3.display();
	f3=f1*f2;
	cout<<"The product of two fraction is ";
	f3.display();
	f3=f1/f2;
	cout<<"The division of two fraction is ";
	f3.display();
	f1==f2;
	return 0;
}