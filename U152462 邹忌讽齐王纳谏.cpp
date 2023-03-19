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
int f[500007];
inline int find(int x){return x==f[x]? x:f[x]=find(f[x]);}
inline int un(int x,int y){f[find(x)]=find(y);}
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
	int n=read(),m=read(),q=read();
	
	for(register int i=0;i<500007;i++)f[i]=i;
	while(m--)un(read(),read());
	while(q--)puts(((find(read())==find(read()))?("Yes"):("No")));
	
	return 0;
}
