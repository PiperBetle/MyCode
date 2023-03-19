#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int x,y,a,b;
	
	while(cin>>a>>b>>n)
	{
		x=y=0;
		for(;;)
		{
			if(y==b)cout<<"empty B\n",y=0;
			if(x==0)cout<<"fill A\n",x=a;
			cout<<"pour A B\n";y+=x;
			if(y>b)x=y-b,y=b;else x=0;
			if(x==n||y==n)break;
		}
		cout<<"success\n";
	}

	return 0;
}
