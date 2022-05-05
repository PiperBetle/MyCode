#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int a,b,c,d;
	int x,y;
	
	scanf("%d/%d",&a,&b);
	while(scanf("%d/%d",&c,&d)!=EOF)
	{
//		a  c    a*d  c*b
//		b  d    b*d  d*b
		x=gcd(b,d);
        a*=d/x;
        c*=b/x;
        a+=c;
        b*=d/x;
        x=gcd(a,b);
        a/=x;
        b/=x;
	}
	if(b<0)
	{
		a=-a;
		b=-b;
	}
	if(b==1)printf("%d",a);
	else printf("%d/%d",a,b);
	
	return 0;
}
