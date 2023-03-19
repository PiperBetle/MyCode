#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t,ans=0,sum,w;
	
	cin>>n>>w;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		a[k]++;
		sum=0;
		for(j=600;j>=0;j--)
		{
			sum+=a[j];
			if(sum>=max(1,i*w/100))
			{
				cout<<j<<" ";
				break;
			}
		}
	}
	
	return 0;
}
