#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
struct block
{
	int h,w;
	int area()
	{
		return h*w;
	}
};
block s[10000007];
int a[10000007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int ans,top;
	
	while(cin>>n)
	{
		if(!n)
			return 0;
		top=0;ans=0;
		s[0].h=s[0].w=0;
		while(n--)
		{
			cin>>t;
			if(t>s[top].h)
			{
				top++;
				s[top].h=t;
				s[top].w=1;
			}
			else
			{
				while(t<=s[top].h)
				{
					ans=max(ans,s[top].area());
					s[top-1].w+=s[top].w;
					top--;
				}
				s[top].w-=s[top+1].w;
				top++;
				s[top].h=t;
				s[top].w+=1;
			}
		}
		while(top)
		{
			ans=max(ans,s[top].area());
			s[top-1].w+=s[top].w;
			top--;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}