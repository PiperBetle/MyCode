#include<iostream>
#include<cstdio>
#include<algorithm>
#define MOD 100
using namespace std;
short a[100001];
inline short read();
inline void write(short xx);
int main()
{
	int n,m,i,j,k;

	n=read();
	m=read();
	for(i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(i=1;i<=m;i++)
	{
		write(a[i]);
		putchar('\n');
	}
	
	return 0;
}

inline short read()
{
    short xx=0,yy=1;
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
inline void write(short xx)
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
