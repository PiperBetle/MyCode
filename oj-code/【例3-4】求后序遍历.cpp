#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[1001],b[1001];
int la,lb;
void qw(int a1,int a2,int b1,int b2)
{
	int i,x;
	for(i=0;;i++)
		if(b[i]==a[a1])
		{
			x=i;
			break;
		}
	if(x>b1)qw(a1+1,a1+x-b1,b1,x-1);
	if(x<b2)qw(a1+x-b1+1,a2,x+1,b2);
	printf("%c",a[a1]);
}
int main()
{
	scanf("%s%s",a,b);
	la=strlen(a);
	lb=strlen(b);
	qw(0,la-1,0,lb-1);
	
	return 0;
}
