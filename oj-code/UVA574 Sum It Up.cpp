#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int a[1007],b[1007],ans[1007][1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	while(cin>>t>>n)
	{
		if(!t&&!n)return 0;
		memset(ans,0,sizeof ans);m=0;
		for(i=1;i<=n;i++)cin>>a[i];
		std::sort(a+1,a+1+n,std::greater<int>());
		for(i=1;i<=(1<<n);i++)
		{
			b[1]++;
			for(j=1;j<=n;j++)if(b[j]>1)b[j]=0,b[j+1]++;else break;
			int sum=0,hash=0;
			for(j=1;j<=n;j++)sum+=a[j]*b[j];
			if(sum!=t)continue;
			ans[++m][0]=0;
			for(j=1;j<=n;j++)if(b[j])ans[m][++ans[m][0]]=a[j];
			for(j=1;j<m;j++)
			{
				if(ans[j][0]!=ans[m][0])continue;
				bool flag=0;
				for(k=1;k<=ans[j][0];k++)if(ans[j][k]!=ans[m][k])flag=1;
				if(flag)continue;
				m--;break;
			}
		}
		if(m==0)cout<<"NONE\n";
		else cout<<"Sums of "<<m<<'\n';
		for(i=1;i<=m;i++)
		{
			cout<<ans[i][1];
//			for(j=2;j<=ans[i][ans[i][0]];j++)cout<<'+'<<ans[i][j];
			for(j=2;j<=12;j++)cout<<'+'<<ans[i][j];
			cout<<'\n';
		}
	}
	
	return 0;
}
