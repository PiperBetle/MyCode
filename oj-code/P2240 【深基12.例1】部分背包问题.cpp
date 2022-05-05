#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct sth
{
	int m;
	int V;
	double wtd;
};
sth a[1001];
int cmp(sth x,sth y)
{
	return x.wtd>y.wtd;
}
int main()
{
	int i,j,k;
	int n,T;
	double w;
	
//	cin>>T;
//	while(T--)
	{
		cin>>n>>w;
		for(i=1;i<=n;i++)
		{
			cin>>a[i].V>>a[i].m;
			a[i].wtd=(double)a[i].m/(double)a[i].V;
		}
		sort(a+1,a+1+n,cmp);
//		for(i=1;i<=n;i++)
//		{
//			cout<<a[i].m<<" "<<a[i].V<<" "<<a[i].wtd<<endl;
//		}
		double ans=0;
		for(i=1;i<=n;i++)
		{
			if(a[i].V>w)
			{
				ans=ans+w*a[i].wtd;
				break;
			}
			else
			{
				ans+=a[i].m;
				w-=a[i].V;
			}
		}
		printf("%.2f\n",ans);
	}
	
	return 0;
}
