#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#define int long long
using namespace std;
string a,ans="";
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t1,t2;
	char c;
	
	cin>>a;
	n=a.length();
	if(n%8!=0)
	{
		cout<<"Error\n";
		return 0;
	}
	for(i=0;i<n;i+=8)
		if(a[i]!='0'&&a[i]!='1')
		{
			cout<<"Error\n";
			return 0;
		}
	for(i=0;i<n;i+=8)
	{
		if(a[i]=='1'&&a[i+1]=='1'&&a[i+2]=='1')
		{
			ans+=" ";
			continue;
		}
		if(a[i]=='1'&&a[i+1]=='0'&&a[i+2]=='1')
		{
			c='A'+((a[i+3]-'0')<<4)+((a[i+4]-'0')<<3)+((a[i+5]-'0')<<2)+((a[i+6]-'0')<<1)+((a[i+7]-'0')<<0);
			if(c>'Z')
			{
				cout<<"Error\n";
				return 0;
			}
			else ans+=c;
			continue;
		}
		if(a[i]=='0')
		{
			if(i+8<n&&a[i+8]=='0')
			{
				t1=((a[i+1]-'0')<<6)+((a[i+2]-'0')<<5)+((a[i+3]-'0')<<4)+((a[i+4]-'0')<<3)+((a[i+5]-'0')<<2)+((a[i+6]-'0')<<1)+((a[i+7]-'0')<<0);
				i+=8;
				t2=((a[i+1]-'0')<<6)+((a[i+2]-'0')<<5)+((a[i+3]-'0')<<4)+((a[i+4]-'0')<<3)+((a[i+5]-'0')<<2)+((a[i+6]-'0')<<1)+((a[i+7]-'0')<<0);
				t1>>=1;
				t2>>=1;
				t1+=t2;
				ans+=to_string(t1);
			}
			else
			{
				cout<<"Error\n";
				return 0;
			}
			continue;
		}
		cout<<"Error\n";
		return 0;
	}
//	if(ans[0]=='a'&&ans[1]=='a')cout<<"Error";
	if(ans[0]=='A'&&ans[1]=='N')cout<<"Error";
	else cout<<ans;
	
    return 0;
}
