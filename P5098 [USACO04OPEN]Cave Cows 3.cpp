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
inline int read();
inline void write(int xx);
int main()
{
	int i,j,k;
	int n,t,tt,ans=-1;
	int a1=-1,a2=99999999,a3=-1,a4=99999999;
	int x,y;
	
	n=read();
	while(n--)
	{
		x=read();
		y=read();
		a1=max(a1,x+y);
        a2=min(a2,x+y);
        a3=max(a3,x-y);
        a4=min(a4,x-y);
	}
	write(max(a1-a2,a3-a4));
    
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
