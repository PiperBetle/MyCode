#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
std::string a,b;
int kmp[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;

	cin>>a>>b;
	int la=a.length(),lb=b.length();
	a=" "+a;b=" "+b;
	for(j=0,i=2;i<=lb;i++)
	{
		while(j&&b[i]!=b[j+1])j=kmp[j];
		if(b[i]==b[j+1])j++;
		kmp[i]=j;
	}
	for(j=0,i=1;i<=la;i++)
	{
		while(j&&a[i]!=b[j+1])j=kmp[j];
		if(a[i]==b[j+1])j++;
		if(j==lb)cout<<i-lb+1<<'\n',j=kmp[j];
	}
	for(i=1;i<=lb;i++)cout<<kmp[i]<<' ';
	
	return 0;
}