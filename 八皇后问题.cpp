#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int a[17],b[17],c[17],d[17],q[17][17];
int ans=0;
void step(int x)
{
	int i,j;
	if(x==9)
	{
		ans++;
		cout<<"No. "<<ans<<endl;
		for (i=1;i<=8;i++)
		{
			for (j=1;j<=8;j++)cout<<q[i][j]<<' ';
			cout<<'\n';
		}
	}
	for(i=1;i<=8;i++)
	{
		if(a[i]==0&&b[x]==0&&c[i+x]==0&&d[i-x+10]==0)
		{
			q[i][x]=1;
			a[i]=1;b[x]=1;c[i+x]=1;d[i-x+10]=1;
			step(x+1);
			q[i][x]=0;
			a[i]=0;b[x]=0;c[i+x]=0;d[i-x+10]=0;
		} 
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	step(1);
	return 0;
}
