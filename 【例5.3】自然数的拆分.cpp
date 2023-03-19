#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int n,m,a[101],b[101],len=1;
void pr(int t)
{
	if(t!=2)
	{
		cout<<n<<'='<<a[1];
		for(int i=2;i<=t-1;i++)cout<<"+"<<a[i];
		cout<<endl;
	}
}
void s(int min,int t)
{
	for(int i=min;i<=t;i++)
	{
		a[len]=i;
		len++;
		t-=i;
		if(t==0)pr(len);
		s(i,t);
		t+=i;
		len--;
	}
}
int main()
{
	cin>>n;
	s(1,n);
	
	return 0;
}
