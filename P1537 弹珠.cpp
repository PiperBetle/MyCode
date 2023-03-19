#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
std::vector<int>a;
int f[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	
	for(k=1;;k++)
	{
		a.clear();m=n=0;
		for(j=1;j<=6;j++)for(cin>>t,m+=t*j,i=1;t;t-=i,i<<=1)
			if(i>=t){a.emplace_back(t*j);break;}else a.emplace_back(i*j);
		if(!m)return 0;
		cout<<"Collection #"<<k<<":\n";
		if(m&1){cout<<"Can't be divided.\n\n";continue;}
		memset(f,0,sizeof f);
		for(auto it:a)for(j=m>>1;j>=it;j--)f[j]=std::max(f[j],f[j-it]+it);
		for(j=0;j<=(m>>1);j++)if(f[j]==(m>>1))n=1;
		cout<<(n?"Can be divided.\n\n":"Can't be divided.\n\n");
	}
	
	return 0;
}