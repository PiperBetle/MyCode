#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
#define eps 1e-5
using namespace std;
struct point{double x,y;};
inline double dis(point x,point y){return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));}
point a,b,c,d;
double p,q,r;
double p2p(point ab,double m)
{
	point cd;
	cd.x=c.x+(d.x-c.x)*m;
	cd.y=c.y+(d.y-c.y)*m;
	return dis(ab,cd)/r+dis(cd,d)/q;
}
double check(double m)
{
	point ab;
	ab.x=a.x+(b.x-a.x)*m;
	ab.y=a.y+(b.y-a.y)*m;
	double left=0.0,right=1.0,midl,midr;
	while(left+eps<right)
	{
		midl=(left+left+right)/3.0;
		midr=(left+right+right)/3.0;
		if(p2p(ab,midl)<p2p(ab,midr))
			right=midr;
		else
			left=midl;
	}
	return p2p(ab,right)+dis(a,ab)/p;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	double left=0.0,right=1.0,midl,midr;
	
	cin>>a.x>>a.y>>b.x>>b.y;
	cin>>c.x>>c.y>>d.x>>d.y;
	cin>>p>>q>>r;
	while(left+eps<right)
	{
		midl=(left+left+right)/3.0;
		midr=(left+right+right)/3.0;
		if(check(midl)<check(midr))
			right=midr;
		else
			left=midl;
	}
	printf("%.2Lf\n",check(right));
	
	return 0;
}