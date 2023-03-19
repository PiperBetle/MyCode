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
#include<list>//头文件
using namespace std;
inline long long read();//快读不解释
long long a[1000001];
int main()
{
	freopen("@.in","r",stdin);
	freopen("@.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	long long i,j,k;
	
	long long n=read();
	long long m=read();
	long long sum=0;
	for(i=1;i<=n;i++)a[i]=read();
	while(m--)
	{
		long long t=read();
		if(t==1)a[read()]=read()-sum;//把a[x]赋值为y-sum,这时a[x]+sum就是y的值
		if(t==2)sum+=read();//把读入的值累加到sum里
		if(t==3)printf("%d\n",a[read()]+sum);//输出a[x]
	}
	
	return 0;
}
inline long long read()
{
    long long _x=0,_op=1;
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
