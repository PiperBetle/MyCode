#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define int long long
using namespace std;
string a;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=0;
	int p,f=-1;
	
	cin>>n>>m;
	cin>>a;
	a=" "+a;
	for(i=1;;i++)
		if(a[i]=='.')
		{
			p=i;
			break;
		}
	
	for(i=p;i<=n;i++)
		if(a[i]>='5')
		{
			n=i-1;
			if(a[i-1]=='.')
			{
				PoP:
				a[i-2]++;
				for(i=i-2;i>=1;i--)
					if(a[i]=='9'+1)
					{
						a[i]='0';
						a[i-1]++;
					}
				if(a[0]>0)
					i=0;
				else
					i=1;
				for(;i<p-1;i++)
					cout<<a[i];
				return 0;
			}
			else
			{
				rew:
					
				a[i-1]++;
				if(a[i-1]<=4)
				{
					for(i=1;i<=n;i++)
						cout<<a[i];
					return 0;
				}
				m--;n--;
				if(m==0)
				{
					for(i=1;i<=n;i++)
						cout<<a[i];
					return 0;
				}
				
				if(a[i-1]=='5')
				{
					i--;
					goto rew;
				}
				if(a[i-1]=='.')
					goto PoP;
			}
		}
	for(i=1;i<=n;i++)
		cout<<a[i];
	
    return 0;
}
