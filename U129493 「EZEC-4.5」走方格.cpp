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
int a[2001][2001],b[2001][2001];
int ans=99999999;
int main()
{
	int i,j,k;
	int n,m;
	int ii,jj,t;
	
	n=read();
	m=read();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[i][j]=read();
		}
	}
	for(ii=1;ii<=n;ii++)
	{
		for(jj=1;jj<=m;jj++)
		{
			t=a[ii][jj];
			a[ii][jj]=0;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					if((i==1)&&(j==1))
					{
						b[1][1]=a[1][1];
						continue;
					}
					if(i==1)
					{
						b[1][j]=b[1][j-1]+a[1][j];
						continue;
					}
					if(j==1)
					{
						b[i][1]=b[i-1][1]+a[i][1];
						continue;
					}
					b[i][j]=max(b[i-1][j],b[i][j-1])+a[i][j];
				}
			}
			a[ii][jj]=t;
			ans=min(ans,b[n][m]);
		}
	}
	write(ans);
	
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
