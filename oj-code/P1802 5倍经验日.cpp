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
int win[1001],lose[1001],use[1001];
long long a[1001];
int main()
{
	int i,j,k;
	int n,m;
	
	n=read();
	m=read();
    for(i=1;i<=n;i++)
    	scanf("%d%d%d",lose+i,win+i,use+i);
    for(i=1;i<=n;i++)
    {
        for(j=m;j>=use[i];j--)
        	a[j]=max(a[j]+lose[i],a[j-use[i]]+win[i]);
        for(j=use[i]-1;j>=0;j--)
			a[j]+=lose[i];
    }
    printf("%lld",5*a[m]);
	
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
