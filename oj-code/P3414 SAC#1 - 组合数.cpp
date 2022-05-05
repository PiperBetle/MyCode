#include<iostream>
#include<cstdio>
#define MOD 6662333
#define int long long
using namespace std;
int b,p,k,a;
int quick(int p)
{
	if(p==0)return 1;
	int t=quick(p/2)%MOD;
	t=(t*t)%MOD;
	if(p%2==1)t=(t*2)%MOD;
	return t;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	cout<<quick(n-1)%MOD;
		
	return 0;
}
