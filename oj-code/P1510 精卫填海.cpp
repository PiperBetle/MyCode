#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int w[10007],v[10007],f[10007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int c,V,ans=-1;
	
	cin>>V>>n>>c;
	for(i=1;i<=n;i++)
	    cin>>w[i]>>v[i];
	for(i=1;i<=n;i++)
		for(j=c;j>=v[i];j--)
		{
			f[j]=max(f[j],f[j-v[i]]+w[i]);
		    if(f[j]>=V)ans=max(ans,c-j);   
		}
	if(ans==-1)cout<<"Impossible";
	else cout<<ans;
		
	return 0;
}
