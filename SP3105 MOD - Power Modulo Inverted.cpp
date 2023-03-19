#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int qp(int a,int b,int p,int t=1){for(;b;b>>=1,a=a*a%p)if(b&1)t=t*a%p;return t;}
inline void exgcd(int a,int b,int &x,int &y){if(!b){x=1;y=0;return;}exgcd(b,a%b,y,x);y-=a/b*x;}
inline int inv(int a,int p){int x,y;exgcd(a,p,x,y);return (x%p+p)%p;}
std::unordered_map<int,int>map;
int bsgs(int a,int b,int p)
{
	map.clear();
	int size=ceil(sqrt(p)),mul=b;
	for(int i=1;i<=size;i++)map[mul=mul*a%p]=i;
	int step=qp(a,size,p);mul=1;
	for(int i=1;i<=size;i++)if(map.count(mul=mul*step%p))return i*size-map[mul];
	return -1;
}
inline int exbsgs(int a,int b,int p)
{
	if(b==1||p==1)return 0;
	int g=gcd(a,p),cnt=0,mul=1;
	while(g!=1)
	{
		if(b%g)return -1;
		b/=g;p/=g;
		cnt++;mul=mul*a/g%p;
		if(mul==b)return cnt;
		g=gcd(a,p);
	}
	int ans=bsgs(a,b*inv(mul,p)%p,p);
	if(ans==-1)return -1;return ans+cnt;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,p;

	while(cin>>n>>p>>m)
	{
		if(!n&&!m&&!p)return 0;
		int k=exbsgs(n%p,m%p,p);
		if(k==-1)cout<<"No Solution\n";
		else cout<<k<<'\n';
	}

	return 0;
}