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
	
	int y=read();
	int m=5;
	int sum=0;
	for(i=1;;i++)
	{
		int d=i;
		int f=(14-m)/12;
    	int yy=y-f;
		int mm=m+12*f-2;
		int t=(d+y+31*mm/12+yy/4-yy/100+yy/400)%7;
		if(t==0)sum++;
		if(sum==2)
		{
			write(i);
			return 0;
		}
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
