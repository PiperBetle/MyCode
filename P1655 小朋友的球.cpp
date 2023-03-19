#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(a) (((a)>0)?(a):-(a))
#define int long long
using namespace std;
string f[107][107];
string add(string aa,string bb)
{
	string cc;
	int a[1007]={0},b[1007]={0},c[1007]={0};
	int la=aa.length(),lb=bb.length();
	for(int i=1;i<=la;i++)a[i]=aa[la-i]-'0';
	for(int i=1;i<=lb;i++)b[i]=bb[lb-i]-'0';
	int lc=max(la,lb);
	for(int i=1;i<=lc;i++)
	{
		c[i]+=a[i]+b[i];
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	if(c[lc+1]>0)lc++;
	for(int i=lc;i>=1;i--)cc+=c[i]+'0';
	return cc;
}
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
	int n,m,ans=0;
	
	for(i=1;i<=100;i++)
		f[i][1]="1";
	for(i=2;i<=100;i++)
		for(j=1;j<=i;j++)
			f[i][j]=add(f[i-1][j-1],multiply(f[i-1][j],j));
	while(cin>>n>>m)
		if(n<m)cout<<"0\n";
		else cout<<f[n][m]<<'\n';
	
    return 0;
}
