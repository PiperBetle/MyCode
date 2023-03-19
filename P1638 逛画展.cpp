#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[1000007],f[1000007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k=1;
	int n,m,t=0;
	int left,right,len=1e9;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(f[a[i]]==0)t++;
		f[a[i]]=i;
		while(k!=i&&k<f[a[k]])k++;
		if((t==m)&&(i-k+1<len))
		{
			len=i-k+1;
			left=k;
			right=i;
		}
	}
	cout<<left<<" "<<right;
	
	return 0;
}
