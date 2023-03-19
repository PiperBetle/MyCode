#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
double a,b,c,k,k1,k2,l,A,B,C;
double f(double x)
{
	return a*x*x+b*x+c;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int n,p,T;
	
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;
		cin>>n;
		while(n--)
		{
			cin>>p;
			if(p==1)
			{
				cin>>k;
				c=c+k;
				continue;
			}
			if(p==2)
			{
				cin>>k;
				A=a;B=b;C=c;
				b=B-2*A*k;
				c=A*k*k-B*k+C;
				continue;
			}
			if(p==3)
			{
				cin>>k1>>k2;
				A=a;B=b;C=c;
				a=-A;
				b=4*A*k1+B;
				c=2*k2-4*A*k1*k1-2*B*k1-C;
				continue;
			}
			if(p==4)
			{
				cin>>k1>>k2;
				l=-b/2.0/a;
				double maxn=max(f(k1),f(k2));
				double minn=min(f(k1),f(k2));
				if(k1<l&&l<k2)
				{
					maxn=max(maxn,f(l));
					minn=min(minn,f(l));
				}
				printf("%.2f %.2f\n",minn,maxn);
				continue;
			}
			if(p==5)
			{
				double x,y,z;
				cin>>x>>y>>z;
				x-=a;y-=b;z-=c;
				double delta=y*y-4*x*z;
				if(delta>=0)printf("2\n");
				else printf("0\n");
				continue;
			}
		}
		
		l=-b/2.0/a;
		printf("%.2f\n",f(l));
	}
	
	return 0;
}
