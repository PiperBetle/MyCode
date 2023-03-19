#include<iostream>
#include<iomanip>
using namespace std;
int a[21],b[21],c[21],x,y;
void pr()
{
	int i;
	
	for(i=1;i<=x;i++)cout<<setw(5)<<c[i];
	cout<<endl;
}
void s(int n)
{
	int i;
	
	if(n>x)return;
	for(i=1;i<=x;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			c[n]=i;
			if(n==x)
			{
				pr();
			}
			s(n+1);
			b[i]=0;
		}
	}
}
int main()
{
	int i;
	
	cin>>x;
	for(i=1;i<=x;i++)
	{
		b[i]=0;
	}
	s(1);

	return 0;
}
