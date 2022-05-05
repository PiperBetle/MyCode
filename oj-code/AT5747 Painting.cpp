#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int n,m,k;
	
	scanf("%d%d%d",&n,&m,&k);
	n=max(n,m);
	if(k%n)printf("%d",k/n+1);
	else printf("%d",k/n);
	
	return 0;
}
