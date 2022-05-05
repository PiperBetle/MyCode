#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[10007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m=-1,t;
	int T,p=1;
	
	for(i=1;i<=1000;i++)
	{
		if((p%3==0)||(p%10==3))p++;
		if((p%3==0)||(p%10==3))p++;
		if((p%3==0)||(p%10==3))p++;
		if((p%3==0)||(p%10==3))p++;
		if((p%3==0)||(p%10==3))p++;
		a[i]=p;
		p++;
	}
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<a[n]<<endl;
	}
	
	return 0;
}
