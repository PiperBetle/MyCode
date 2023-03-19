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
void exgcd(int a,int b,int &x,int &y){if(!b){x=1;y=0;}else{exgcd(b,a%b,y,x);y-=a/b*x;}}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int a,b,c;
	int x,y,g;
	
	cin>>a>>b>>c;
	exgcd(a,b,x,y);
	g=a*x+b*y;
	if(c%g)return cout<<-1,0;
	x=c/g*x;y=c/g*y;
	cout<<-x<<' '<<-y;

	return 0;
}
