#include<cstdio>
#include<iostream>
#include<cstring>
#define len n
using namespace std;
char s[200009];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	long long len,ans=0;
	
	scanf("%s",s);
	len=strlen(s);
	for(i=1;i<=n;i++)
	{
		ans=ans+i*(n+1-i);
	}
	printf("%lld",ans);
	
	return 0;
}
