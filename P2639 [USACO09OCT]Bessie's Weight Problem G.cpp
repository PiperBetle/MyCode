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
int w[1000001],a[1000001]={0};
int main()
{
//	std::ios::sync_with_stdio(false);
	int t,m,i,j,k,h,n;
	
	h=read();
	n=read();
	for(i=1;i<=n;i++)
	{
		w[i]=read();
	}
	for(i=1;i<=n;i++)
	{
		for(j=h;j>=w[i];j--)
		{
			if(a[j-w[i]]+w[i]>a[j])
			{
				a[j]=a[j-w[i]]+w[i];
			}
		}
	}
	write(a[h]);
    
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
