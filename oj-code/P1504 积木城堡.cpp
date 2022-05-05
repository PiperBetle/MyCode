#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int a[1000007],f[1000007],s[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	int ans=-1,sum;
	
	cin>>n;
	for(k=1;k<=n;k++)
	{
		memset(a,0,sizeof a);
		memset(f,0,sizeof f);
		sum=m=0;//m表示长度 
		while(cin>>t)
		{
			if(t==-1)break;
			m++;
			a[m]=t;
			sum+=a[m];
		}
		f[0]=1;
		ans=max(ans,sum);
		for(i=1;i<=m;i++)
			for(j=sum;j>=a[i];j--)
				if(f[j]==0&&f[j-a[i]]!=0)
				{
					f[j]=1;
					s[j]++;
				}
	}
	for(;ans>0;ans--)
		if(s[ans]==n)
			break;
	cout<<ans;
	
    return 0;
}
