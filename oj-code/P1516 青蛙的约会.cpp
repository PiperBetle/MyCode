#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
inline void exgcd(int a,int b,int &x,int &y){if(!b){x=1;y=0;return;}exgcd(b,a%b,y,x);y-=a/b*x;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int x,y,l;

	cin>>x>>y>>m>>n>>l;
	int a=n-m,b=l,c=x-y;
	if(a<0)a=-a,c=-c;
	exgcd(a,b,x,y);
	int g=a*x+b*y;
	if(c%g)return cout<<"Impossible",0;
	a/=g;b/=g;c/=g;
	cout<<(c*x%b+b)%b<<'\n';

	return 0;
}