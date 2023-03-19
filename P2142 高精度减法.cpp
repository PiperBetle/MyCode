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
char aa[5000007],bb[5000007],tt[5000007];
int a[5000007],b[5000007],c[5000007];
int la,lb,lc,x,i;
int main()
{
	scanf("%s%s",aa,bb);
    if ((strlen(aa)<strlen(bb))||(strlen(aa)==strlen(bb)&&strcmp(aa,bb)<0))
	{
		strcpy(tt,aa);
		strcpy(aa,bb);
		strcpy(bb,tt);
		printf("-");
	}
    la=strlen(aa);lb=strlen(bb);
    for(i=0;i<=la-1;i++)a[la-i]=aa[i]-'0';
    for(i=0;i<=lb-1;i++)b[lb-i]=bb[i]-'0';

    lc=1;
	while((lc<=la)||(lc<=lb))
	{
		if(a[lc]>=b[lc])
			c[lc]=a[lc]-b[lc];
		else
		{
			c[lc]=a[lc]-b[lc]+10;
			a[lc+1]--;
		}
		lc++;
	}
	lc=lc-1;

	while((c[lc]==0)&&(lc>1))lc--;
    for(i=lc;i>=1;i--)cout<<c[i];

    return 0;
}
