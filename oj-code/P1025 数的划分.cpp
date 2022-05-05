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
	k=read(); for (int i=1;i<=n;i++) {f[i][1]=1;f[i][0]=1;}for (int x=2;x<=k;x++) {f[1][x]=0;f[0][x]=0;}
	for(i=1;i<=n;i++)a[i][1]=a[i][0]=1;
	for(i=2;i<=k;i++)a[1][i]=a[0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			
		}
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
