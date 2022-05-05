#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
char a[1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t,ans=0;
	
	gets(a);
	for(i=0;i<strlen(a);i++)
		if((('0'<=a[i])&&(a[i]<='9'))||(('a'<=a[i])&&(a[i]<='z'))||(('A'<=a[i])&&(a[i]<='Z')))ans++;
	cout<<ans;
	
	return 0;
}

