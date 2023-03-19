#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int Toint(char x)
{
	if(('a'<=x)&&(x<='z'))
		return x-'a'+1;
	return x-'A'+27;
}
char Tochar(int x)
{
	if(x<=26)
		return x-1+'a';
	return x-27+'A';
}
int f[107][107];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	char u,v,p;
	int ans=1e9;
	
	memset(f,0x3f,sizeof f);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>u>>v>>t;
		f[Toint(u)][Toint(v)]=min(f[Toint(u)][Toint(v)],t);
		f[Toint(v)][Toint(u)]=min(f[Toint(v)][Toint(u)],t);
	}
	for(k=1;k<=52;k++)
		for(i=1;i<=52;i++)
			for(j=1;j<=52;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(i=27;i<=51;i++)
		if(f[i][52]<=ans)
		{
			ans=f[i][52];
			p=i+'A'-27;
		}
	cout<<p<<" "<<ans;
	
	return 0;
}
