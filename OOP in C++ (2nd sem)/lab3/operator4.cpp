//calss matrix of size 3x3.Overload the - to negate the numbers stored
#include<iostream>
using namespace std;
class Matrix
{
	int matx[3][3];
	public:
		int i,j;
		void setdata()
		{
			cout<<"Enter the matrix elements: "<<endl;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					cin>>matx[i][j];
				}
			}
		}
		void display()
		{
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					cout<<matx[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void operator -()
		{
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					matx[i][j]=-matx[i][j];
				}
			}
		}
};
int main()
{
	Matrix m;
	m.setdata();
	cout<<"The given matrix is:"<<endl;
	m.display();
	-m;
	cout<<"The result matrix is:"<<endl;
	m.display();
	return 0;
}