#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
using std::cin;using std::cout;
int f[27][27],ans[27],cnt;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k,n,m,u,v,p;
	char uu,vv,t;
	cin>>n>>m;
	memset(f,0x3f,sizeof f);
	for(i=1;i<=n;i++)f[i][i]=0;
	for(p=1;p<=m;p++){
		cin>>uu>>t>>vv;
		u=uu-64;v=vv-64;
		if(u==v)return cout<<"Inconsistency found after "<<p<<" relations.",0;
		if(f[v][u]!=inf)return cout<<"Inconsistency found after "<<p<<" relations.",0;
		f[u][v]=1;
		for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)
			f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
		for(cnt=0,i=1;i<=n;i++){
			int p1=0,p2=0;
			for(j=1;j<=n;j++){
				if(i==j)continue;
				if(f[i][j]!=inf&&f[j][i]!=inf)return cout<<"Inconsistency found after "<<p<<" relations.",0;
				if(f[j][i]!=inf)p1++;
				if(f[i][j]!=inf)p2++;
			}
			if(p1+p2==n-1)ans[p1+1]=i,cnt++;
		}
		if(cnt==n){
			cout<<"Sorted sequence determined after "<<p<<" relations: ";
			for(i=1;i<=n;i++)cout<<char(ans[i]+'A'-1);
			cout<<".\n";
			return 0;
		}
	}
	cout<<"Sorted sequence cannot be determined.";
	return 0;
}