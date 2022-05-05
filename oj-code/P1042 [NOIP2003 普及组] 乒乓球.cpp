#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define int long long
using namespace std;
char a[10000007];
int l;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	char c;
	
	for(;;)
	{
		cin>>c;
		if(c=='W'||c=='L')
		{
			l++;
			a[l]=c;
		}
		if(c=='E')break;
	}
//	for(i=1;i<=l;i++)cout<<a[i];
//	cout<<endl<<l<<endl;
	
	n=0;m=0;
	for(i=1;i<=l;i++)
	{
		if(a[i]=='W')n++;
		if(a[i]=='L')m++;
		if((n>=11||m>=11)&&(abs(n-m)>=2))
		{
			cout<<n<<":"<<m<<"\n";
			n=m=0;
		}
	}
	cout<<n<<":"<<m<<"\n\n";
	n=m=0;
	for(i=1;i<=l;i++)
	{
		if(a[i]=='W')n++;
		if(a[i]=='L')m++;
		if((n>=21||m>=21)&&(abs(n-m)>=2))
		{
			cout<<n<<":"<<m<<"\n";
			n=m=0;
		}
	}
	cout<<n<<":"<<m<<"\n";
	
    return 0;
}
