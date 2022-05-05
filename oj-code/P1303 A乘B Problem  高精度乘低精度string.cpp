#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(a) (((a)>0)?(a):-(a))
#define int long long
using namespace std;
string multiply(string aa,int nn)
{
	string cc;
	int a[1007]={0},c[1007]={0},jw=0;
	int la=aa.length(),lc=la;
	for(int i=1;i<=la;i++)a[i]=aa[la-i]-'0';
	for(int i=1;i<=lc;i++)
	{
		c[i]=a[i]*nn+jw;
		jw=c[i]/10;
		c[i]%=10;
	}
	for(;;)
		if(jw>0)
		{
			lc++;
			c[lc]=jw%10;
			jw/=10;
		}
		else break;
	for(int i=lc;i>=1;i--)cc+=c[i]+'0';
	return cc;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	string n;
	int m; 
	
	cin>>n>>m;
	cout<<multiply(n,m);
	
    return 0;
}
