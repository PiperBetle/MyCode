#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int to(char c)
{
	if(c-'0'<10)return c-'0';
	return c-'a';
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	long long i,j=1,k,n,m,t,ans=0;
	char a[1007];
	
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		ans+=to(a[i])*j;
		j*=16;
	}
	cout<<ans<<endl;
	
	return 0;
}

