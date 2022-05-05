#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y,T,p;
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		p=1;
		while(p*p<n)p++;
		t=p*p;
		x=p;y=1;
		for(i=1;i<=t-n+1;i++)
			if(i<=p)y++;
			else x--;
		cout<<x<<" "<<y-1<<"\n";
	}
	
	return 0;
}
