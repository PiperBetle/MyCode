#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int data[1000007],p[1000007],pre[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m=0,t;
	char c;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='a')
		{
			cin>>t;
			data[++m]=t;
			p[i]=m;
			pre[p[i]]=p[i-1];
		}
		if(c=='s')
		{
			p[i]=pre[p[i-1]];
		}
		if(c=='t')
		{
			cin>>t;
			p[i]=p[t-1];
		}
		cout<<(p[i]?data[p[i]]:-1)<<'\n';
	}
	
	return 0;
}
