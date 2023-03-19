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
using namespace std;
int main()
{
	int n,a[10001],m,i;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	while(m--)next_permutation(a+1,a+1+n);
	for(i=1;i<=n;i++)printf("%d ",a[i]);
	
	return 0;
}
