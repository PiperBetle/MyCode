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
inline void write(int _x);
struct sb
{
	int l,r;
	int val;
};
sb b[500001];
int a[500001];
bool c[500001];
int main()
{
	int i,j,k;
	int n,m;
	int minn,flag;
	int ii,jj,t;
	
	n=read();
	m=read();
	for(i=0;i<=n;i++)a[i]=i;
	for(i=1;i<=m;i++)
	{
		b[i].l=read();
		b[i].r=read();
		b[i].val=read();
	}
	for(i=1;i<=24;i++)
	{
		flag=1;
		for(i=1;i<=m;i++)
		{
			for(j=0;j<=n;j++)c[i]=0;
			for(j=b[i].l;j<=b[i].r;j++)
				c[a[j]]=1;
			minn=n+1;
			for(j=0;j<=n;j++)
				if(c[j]==0)
				{
					minn=j;
					break;
				}
			if(minn!=b[i].val)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			for(i=0;i<=n;i++)
			{
				write(a[i]);
				putchar(' ');
			}
			return 0;
		}
		next_permutation(a,a+1+n);
	}
	
	return 0;
}
inline int read()
{
    int _x=0,_y=1;
    char _ch=getchar();
    while(_ch<'0'||_ch>'9')
	{
        if(_ch=='-')
            _y=-1;
        _ch=getchar();
    }
    while(_ch>='0'&&_ch<='9')
	{
        _x=(_x<<1)+(_x<<3)+(_ch^48);
        _ch=getchar();
    }
    return _x*_y;
}
inline void write(int _x)
{
    if(_x<0)
	{
    	putchar('-');
		_x=-_x;
	}
    if(_x>9)
    {
    	write(_x/10);
	}
    putchar(_x%10+'0');
}
