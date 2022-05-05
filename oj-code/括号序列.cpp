#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
struct space
{
	int left,right;
};
space a[10000007];
string str;
bool cmp(space x,space y)
{
	return x.left-x.right>y.left-y.right;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n=0,m,T,len;
	int sum1,sum2,LEFT=0,RIGHT=0;
	
	cin>>T;
	while(T--)
	{
		sum1=sum2=0;
		cin>>str;
		len=str.length();
		for(j=0;j<len;j++)
			if(str[j]=='(')
				sum1++;
			else
				if(sum1>0)
					sum1--;
				else
					sum2++;
		if(sum1>0&&sum2>0)
		{
			n++;
			a[n].left=sum1;
			a[n].right=sum2;
		}
		else
		{
			LEFT+=sum1;
			RIGHT+=sum2;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++)
	{
		if(LEFT<a[i].right)
		{
			cout<<"No";
			return 0;
		}
		else
			LEFT+=a[i].left-a[i].right;
	}
	if(LEFT==RIGHT)
		cout<<"Yes";
	else
		cout<<"No";
	
    return 0;
}
