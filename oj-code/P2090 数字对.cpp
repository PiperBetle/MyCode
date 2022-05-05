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
inline void write(int xx);
int minn;
void dfs(int a,int b,int t)
{
	if(t>minn)return;
	if(a<1)return;
	if(b<1)return;
	if((a==1)&&(b==1))
	{
		minn=min(minn,t);
		return;
	}
	if(a>b)dfs(a-b,b,t+1);
	if(a<b)dfs(a,b-a,t+1);
}
int main()
{
//	std::ios::sync_with_stdio(false);
	int t,m,i,j,k,n;
	
	minn=99999999;
	n=read();
	for(i=2;i<=n-1;i++)dfs(i,n,0);
	write(minn);
    
    return 0;
}
inline int read()
{
    int xx=0,yy=1;
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
inline void write(int xx)
{
    if(xx<0)
	{
    	putchar('-');
		xx=-xx;
	}
    if(xx>9)
    {
    	write(xx/10);
	}
    putchar(xx%10+'0');
}
