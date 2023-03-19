#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
inline int qp(int a,int b,int p,int t=1){for(;b;b>>=1,a=a*a%p)if(b&1)t=t*a%p;return t;}
inline void exgcd(int a,int b,int &x,int &y){if(!b){x=1;y=0;return;}exgcd(b,a%b,y,x);y-=a/b*x;}
std::unordered_map<int,int>map;
inline int bsgs(int a,int b,int p)
{
	if(a%p==0)return b%p?-1:1;
	map.clear();
	int size=ceil(sqrt(p)),mul=b%p,step=qp(a,p-2,p);
	for(int i=0;i<=size;i++,mul=mul*step%p)if(!map.count(mul))map[mul]=i;
	mul=1;step=qp(a,size,p);
	for(int i=0;i<=size;i++,mul=mul*step%p)if(map.count(mul))return map[mul]+size*i;
	return -1;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int p,x,y;
	
	cin>>T>>k;
	if(k==1)while(T--)
	{
		cin>>n>>m>>p;
		cout<<qp(n,m,p)<<'\n';
	}
	if(k==2)while(T--)
	{
		cin>>n>>m>>p;
		exgcd(n,p,x,y);
		int g=n*x+p*y;
		if(m%g){cout<<"Orz, I cannot find x!\n";continue;}
		n/=g;p/=g;m/=g;
		cout<<(x*m%p+p)%p<<'\n';
	}
	if(k==3)while(T--)
	{
		cin>>n>>m>>p;
		k=bsgs(n,m,p);
		if(k==-1)cout<<"Orz, I cannot find x!\n";
		else cout<<k<<'\n';
	}

	return 0;
}