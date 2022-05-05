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
bool a[10000001];
int main()
{
	int n,len=0,i;
	
	
	scanf("%d",&n);
	n++;
	for(;;)
	{
		len++;
		a[len]=n%2;
		n/=2;
		if(n==0)break;
	}
	for(i=len-1;i>=1;i--)
		if(a[i]==0)putchar('4');
		else putchar('7');
	
    return 0;
}
