#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read()
{
    int _x=0,_op=1;
    char _ch=getchar();
    while(_ch<'0'||_ch>'9')
	{
        if(_ch=='-')
            _op=-1;
        _ch=getchar();
    }
    while(_ch>='0'&&_ch<='9')
	{
        _x=(_x<<1)+(_x<<3)+(_ch^48);
        _ch=getchar();
    }
    return _x*_op;
}
int main()
{
//	freopen("watersheds.in","r",stdin);
//	freopen("watersheds.out","w",stdout);
	int n,m;
	
	n=read()-1;
	m=read();
	while(n--)m=min(m,read());
	cout<<m;
	
	return 0;
}
