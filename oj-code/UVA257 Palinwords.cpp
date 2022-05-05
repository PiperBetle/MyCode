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
std::string a;
int f[1007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,len;

	while(cin>>a)
	{
		n=a.length();
		m=0;
		for(i=0;i<n-2;i++)
			if(a[i]==a[i+2])
				f[++m]=a[i]*128*128+a[i+1]*128+a[i+2];
		for(i=0;i<n-3;i++)
			if(a[i]==a[i+3]&&a[i+1]==a[i+2])
				f[++m]=a[i]*128*128+a[i+1]*128+a[i+2];
		std::sort(f+1,f+1+m);
		int cnt=1;
		for(i=1;i<m;i++)
			cnt+=(f[i]!=f[i+1]);
		cout<<(cnt>1?a:"")<<(cnt>1?"\n":"");
	}
	
	return 0;
}