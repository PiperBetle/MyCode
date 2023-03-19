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
inline int qp(int a,int b,int p,int t=1){for(;b;b>>=1,a=a*a%p)if(b&1)t=t*a%p;return t;}
inline void exgcd(int a,int b,int &x,int &y){if(!b){x=1;y=0;return;}exgcd(b,a%b,y,x);y-=a/b*x;}
inline int inv(int a,int p){int x,y;exgcd(a,p,x,y);return a*x+p*y==1?(x%p+p)%p:-1;}
std::unordered_map<int,int>map;
inline int bsgs(int a,int b,int p)
{
	map.clear();
	int size=ceil(sqrt(p)),mul=b%p,step=inv(a,p);
	for(int i=0;i<=size;i++,mul=mul*step%p)map[mul]=i;
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
	int n,m,p;

	cin>>p>>n>>m;
	k=bsgs(n,m,p);
	if(k==-1)cout<<"no solution";
	else cout<<k;

	return 0;
}