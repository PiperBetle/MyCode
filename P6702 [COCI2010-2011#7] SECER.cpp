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
int a[5001];
int main()
{
	int i,j,k;
	int n,m;
	
	n=read();
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		a[i]=666666;
		if(i>2)a[i]=min(a[i],a[i-3]+1);
		if(i>4)a[i]=min(a[i],a[i-5]+1);
	}
	if(a[i]==666666)printf("-1");
	else write(a[i]);
	
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
