#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(a) (((a)>0)?(a):-(a))
#define int long long
using namespace std;
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
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	string n,m;
	
	cin>>n>>m;
	cout<<add(n,m);
	
    return 0;
}
