#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#define int long long
using namespace std;
int a[20000007],b[20000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	t=1;
	for(m=1;;m++)
	{
		if(t<=n)t=t*2;
		else t=(t-n)*2-1;
		if(t==1)break;
	}
	cout<<m;
	
    return 0;
}
