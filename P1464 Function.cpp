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
using namespace std;
inline long long read();
long long a[21][21][21]={0};
long long fun(long long x,long long y,long long z)
{
	if((x<=0)||(y<=0)||(z<=0))return 1;
	if((x>20)||(y>20)||(z>20))return 1048576;
	if(a[x][y][z]!=0)return a[x][y][z];
	if((x<y)&&(y<z))
	{
		a[x][y][z]=fun(x,y,z-1)+fun(x,y-1,z-1)-fun(x,y-1,z);
		return a[x][y][z];
	}
	a[x][y][z]=fun(x-1,y,z)+fun(x-1,y-1,z)+fun(x-1,y,z-1)-fun(x-1,y-1,z-1);
	return a[x][y][z];
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	long long i,j,k;
	long long n,m,t,x,y,z;
	
	for(;;)
	{
		x=read();
		y=read();
		z=read();
		if((x==-1)&&(y==-1)&&(z==-1))return 0;
		printf("w(%lld, %lld, %lld) = %lld\n",x,y,z,fun(x,y,z));
	}
	
	return 0;
}
inline long long read()
{
    long long xx=0,yy=1;
    char chch=getchar();
    while(chch<'0'||chch>'9')
	{
        if(chch=='-')
            yy=-1;
        chch=getchar();
    }
    while(chch>='0'&&chch<='9')
	{
        xx=(xx<<1)+(xx<<3)+(chch^48);
        chch=getchar();
    }
    return xx*yy;
}
