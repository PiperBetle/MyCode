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
#include<list>//ͷ�ļ�
using namespace std;
inline long long read();//���������
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
		if(t==1)a[read()]=read()-sum;//��a[x]��ֵΪy-sum,��ʱa[x]+sum����y��ֵ
		if(t==2)sum+=read();//�Ѷ����ֵ�ۼӵ�sum��
		if(t==3)printf("%d\n",a[read()]+sum);//���a[x]
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
