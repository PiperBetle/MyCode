#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define int __int128
using std::cin;using std::cout;using std::swap;
template<typename any>inline any max(any x,any y){return x<y?y:x;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return 0<x?x:-x;}
signed pt[10000007],len,mif[10000007];
bool pr[10000007];
std::vector<int>s;
int maxn;
inline int qp(int a,int p,int k,int t=1){for(;p;p>>=1,a=a*a%k)if(p&1)t=t*a%k;return t;}
inline bool miller_rabin(int n)
{
	if(n<=10000000)return !pr[n];
	int a,b,k,x=0,y=n-1;
	while(!(y&1))x++,y>>=1;
	for(signed i=1;i<=12&&pt[i]<n;++i)
	{
		a=pt[i];b=qp(a,y,n);
		for(int j=1;j<=x;++j)
		{
			k=b*b%n;
			if(k==1&&b!=1&&b!=n-1)return 0;
			b=k;
		}
		if(b!=1)return 0;
	}
	return 1;
}
inline int gcd(int a, int b)
{
	if(!a)return b;if(!b)return a;
	signed t=__builtin_ctzll(a|b);
	a>>=__builtin_ctzll(a);
	do
	{
		b>>=__builtin_ctzll(b);
		if(a>b)swap(a,b);
		b-=a;
	}while(b);
	return a<<t;
}
inline int pollard_rho(int n)
{
	if(n<=10000000)return mif[n];
	if(miller_rabin(n))return n;
	int c=rand()%n;
	#define f(x) ((x*x+c)%n)
	int x=f(0),y=f(x),g;
	int pre=1;signed l=1;
	while(x!=y)
	{
		for(signed i=l;i;--i)
		{
			x=f(x);y=f(f(y));
			pre=pre*abs(x-y)%n;
			if(x==y||!pre)break;
		}
		if((g=gcd(abs(x-y),n))>1)return g;
		if(l<128)l<<=1;
	}
	return n;
}
inline int read()
{
	int w=0;signed c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=(w<<1)+(w<<3)+(c^48);
	return w;
}
inline void write(int x)
{
	if(x>9)write(x/10);
	putchar(x%10+48);
}
inline void dfs(int n)
{
	if(n==1)return;
	if(miller_rabin(n)){s.emplace_back(n);return;}
	int m=pollard_rho(n);dfs(m);dfs(n/m);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	srand(time(NULL));
	int n,m,t;
	
	pr[1]=1;
	for(signed i=2;i<=10000000;++i)
	{
		if(!pr[i])pt[++len]=i,mif[i]=i;
		for(signed j=1;j<=len&&i*pt[j]<=10000000;j++)
		{
			pr[i*pt[j]]=1;
			mif[i*pt[j]]=pt[j];
			if(i%pt[j]==0)break;
		} 
	}
	for(;;)
	{
		if(!(n=read()))return 0;
		s.clear();
		dfs(n);
		if(n==1){puts("1");continue;}
		std::sort(s.begin(),s.end());
		int cnt=1;
		for(signed i=1;i<s.size();++i)
		{
			if(s[i]!=s[i-1])write(s[i-1]),putchar('^'),write(cnt),cnt=1,putchar(' ');
			else cnt++;
		}
		write(s[s.size()-1]);putchar('^');write(cnt);cnt=1;putchar('\n');
	}
		
	return 0;
}