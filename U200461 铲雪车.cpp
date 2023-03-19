#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	double x,y,sum=0;
	double x1,y1,x2,y2;
	
	cin>>x>>y;
	while(cin>>x1>>y1>>x2>>y2)sum+=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	sum/=10000.0;
	int n=sum;double m=sum-n;
	m*=60.0;
	printf("%lld:",n);
	if(m<10.0)putchar('0');
	printf("%.0Lf",m);

	return 0;
}
