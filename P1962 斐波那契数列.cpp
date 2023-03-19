#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 1000000007
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct jz
{
	int data[3][3];
	jz(){memset(data,0,sizeof data);}
	void build(){for(int i=0;i<3;i++)data[i][i]=1;}
	jz operator *(const jz &b)
	{
		jz c;
		for(int k=1;k<=2;k++)for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)
			c.data[i][j]=(c.data[i][j]+data[i][k]*b.data[k][j]%MOD)%MOD;
		return c;
	}
};
jz a,ans;
jz qp(jz a,int p){jz t;t.build();for(;p;p>>=1,a=a*a)if(p&1)t=t*a;return t;}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	if(n<=2)return cout<<1,0;
	a.data[1][1]=a.data[1][2]=a.data[2][1]=ans.data[1][1]=ans.data[1][2]=1;
	ans=qp(a,n-1);
	cout<<ans.data[1][1]%MOD;
	
	return 0;
}
