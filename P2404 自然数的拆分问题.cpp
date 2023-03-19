#include<iostream>
using namespace std;
int a[201],b[201],x,len;
void pr()
{
	if(len!=2)
	{
		cout<<a[1];
		for(int i=2;i<=len-1;i++)cout<<"+"<<a[i];
		cout<<endl;
	}
}
void s(int minn,int n)
{
	for(int i=minn;i<=n;i++)
	{
		a[len]=i;
		len++;
		n-=i;
		if(n==0)
			pr();
		s(i,n);
		len--;
		n+=i;
	}
}
int main()
{
	cin>>x;
	len=1;
	s(1,x);

	return 0;
}
