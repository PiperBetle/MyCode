#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
string w[30]={"","one","two","three","four","five","six","seven",
"eight","nine","ten","elven","twelve","thirteen","fourteen","fifteen",
"sixteen","seventeen","eighteen","nineteen","twenty","a","both",
"another","first","second","third"}; 
int f[30]={0,1,4,9,16,25,36,49,64,81,0,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=0;
	string s;
	int a[11],l=0;
	
	for(k=1;k<=6;k++)
	{
		cin>>s;
		if(s[0]<='Z')s[0]-'Z'+'z';
		for(i=1;i<=26;i++)
			if(w[i]==s)
			{
				l++;
				a[l]=f[i];
				break;
			}
	}
	if(l==0)
	{
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+l);
	for(i=1;i<=l;i++)
	{
		if(i!=1&&a[i]<10)cout<<0;
		cout<<a[i];
	}
	
    return 0;
}
