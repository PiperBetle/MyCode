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
bool pr[10000007];
int pt[10000007];
int len=0;
void qw(int n)
{
	int i,j;
	for(i=0;i<10000007;i++)pr[i]=1;
	pr[1]=0;
	for(i=2;i<=n;i++)
	{
		if(pr[i])
		{
			len++;
			pt[len]=i;
		}
		for(j=1;j<=len;j++)
		{
			if(i*pt[j]>n)break;
			pr[i*pt[j]]=0;
			if(i%pt[j]==0)break;
		} 
	}
	return;
}
inline int read();
inline void write(int xx);
int main()
{
//	std::ios::sync_with_stdio(false);
	
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	qw(n);
	while(m--)
	{
		k=read();
		write(pt[k]);
		puts("");
	}
	
	return 0;
}
inline int read()
{
    int xx=0,yy=1;
    char chch=getchar();
    while(chch<'0'||chch>'9')
	{
        if(chch=='-')
            yy=-1;
        chch=getchar();
    }
    while(chch>='0'&&chch<='9')
	{
        xx=(xx<<1)+(xx<<3)+(chch^48);
        chch=getchar();
    }
    return xx*yy;
}
inline void write(int xx)
{
    if(xx<0)
	{
    	putchar('-');
		xx=-xx;
	}
    if(xx>9)
    {
    	write(xx/10);
	}
    putchar(xx%10+'0');
}
