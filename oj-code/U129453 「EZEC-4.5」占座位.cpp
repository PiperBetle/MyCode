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
int s(int n,int m)
{
	if((m==0)||(m>n))return 0;
	if((m==1)||(n==m))return 1;
	return m*s(n-1,m)+s(n-1,m-1);
}
int main()
{
	int i,j,k;
	int n,m;
	
	cin>>n>>m;
	cout<<s(n,m);
	
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
