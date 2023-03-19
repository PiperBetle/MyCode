#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
using std::cin;using std::cout;
int pt[7000007],len;
// bool pr[100000007];
std::bitset<100000007>pr;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	cin>>n>>T;
	for(i=2;i<=n;i++)
	{
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=n;j++)
		{
			pr[i*pt[j]]=1;
			if(i%pt[j]==0)break;
		}
	}
	while(T--){cin>>n;cout<<pt[n]<<'\n';}
	
	return 0;
}