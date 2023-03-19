#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define int long long
using namespace std;
int a[5000007],b[5000007],c[5000007];
int la,lb,lc;
string aa,bb;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=0;
	int ta=0,tb=0;
	
	cin>>aa>>bb;
	if(aa[0]=='-'&&bb[0]=='-')
	{
		cout<<'-';
		aa[0]=bb[0]='0';
	}
	if(aa[0]!='-'&&bb[0]!='-')
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		scanf("%s%s",aa,bb);
		la=aa.length();
		lb=bb.length();
		lc=max(la,lb);
		for(i=1;i<=la;i++)
			a[i]=aa[la-i]-'0';
		for(i=1;i<=lb;i++)
			b[i]=bb[lb-i]-'0';
		for(i=1;i<=lc;i++)
		{
			c[i]+=a[i]+b[i];
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
		if(c[lc+1]>0)lc++;
		for(i=lc;i>=1;i--)
			if(c[i]!=0)
				break;
		for(;i>=1;i--)
			cout<<c[i];
	}
	else
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		if(aa[0]=='-')ta=aa[0]='0';//
		if(bb[0]=='-')tb=bb[0]='0';
		la=aa.length();
		lb=bb.length();
		for(i=1;i<=la;i++)
			a[i]=aa[la-i]-'0';
		for(i=1;i<=lb;i++)
			b[i]=bb[lb-i]-'0';
		if(a[la]==0)la--;
		if(b[lb]==0)lb--;
		if("-"+aa==bb||"-"+bb==aa)
		{
			cout<<0;
			return 0;
		}
		
		for(i=max(la,lb);i>=1;i--)
			if(a[i]<b[i])
			{
				for(i=1;i<=max(la,lb);i++)
					swap(a[i],b[i]);
				if(tb=='0')
					cout<<"-";
				ta=tb=0;
				break;
			}
			else if(a[i]>b[i])break;
		if(ta=='0')cout<<"-";
		
		memset(c,0,sizeof c);
	    lc=1;
		while((lc<=la)||(lc<=lb))
		{
			if(a[lc]>=b[lc])
				c[lc]=a[lc]-b[lc];
			else
			{
				c[lc]=a[lc]-b[lc]+10;
				a[lc+1]--;
			}
			lc++;
		}
		lc=lc-1;
		while((c[lc]==0)&&(lc>1))
			lc--;
   		for(i=lc;i>=1;i--)
		   	cout<<c[i];
	}
	
    return 0;
}
