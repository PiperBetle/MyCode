#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define int long long
using namespace std;
char a[1000007],b[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=0;
	int bug=0,p;
	
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	for(i=1,j=1;i<=n;i++,j++)
	{
		if(a[i]!=b[j])
		{
			j--;
			p=i;
			bug++;
		}
	}
	if(bug>1)
	{
		cout<<"0";
		return 0;
	}
	for(i=p-1;i>=1;i--)
		if(a[i]==a[p])bug++;
		else break;
	cout<<bug<<'\n';
	for(i++;i<=p;i++)
		cout<<i<<' ';
	
    return 0;
}
