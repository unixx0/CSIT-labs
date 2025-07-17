//calss matrix of size 3x3.find out m3=m1+m2
#include<iostream>
using namespace std;
class Matrix
{
	int m[3][3];
	public:
		int i,j;
		void setdata()
		{
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					cin>>m[i][j];
				}
			}
		}
		void display()
		{
			cout<<endl<<"The sum of two matrices is: "<<endl;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					cout<<m[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		Matrix operator +(Matrix &obj)
		{
			Matrix M;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					M.m[i][j]=m[i][j]+obj.m[i][j];
				}
			}
			return M;
		}
};
int main()
{
	Matrix m1,m2,m3;
	cout<<"Enter the elements of first matrix:"<<endl;
	m1.setdata();
	cout<<"Enter the elements of second matrix:"<<endl;
	m2.setdata();
    m3=m1+m2;
	m3.display();
	return 0;
}