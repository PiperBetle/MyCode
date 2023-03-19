#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
bool pr[100000001];
int pt[10000001];
int len=0;
void qw(int n)
{
	int i,j;
	for(i=0;i<100000001;i++)pr[i]=1;
	pr[1]=0;
	for(i=2;i<=n;i++)
	{
		if(pr[i])
		{
			len++;
			pt[len]=i;
		}
		for(j=1;j<=len;j++)
		{
			if(i*pt[j]>n)break;
			pr[i*pt[j]]=0;
			if(i%pt[j]==0)break;
		} 
	}
	return;
}
inline int read();
inline void write(int xx);
int main()
{
//	std::ios::sync_with_stdio(false);
	int t,m,i,j,k;
	int w[10001],v[10001],dp[10001]={0};
	
	t=read();
	m=read();
	for(i=1;i<=m;i++)
	{
		w[i]=read();
		v[i]=read();
	}
	for(i=1;i<=m;i++)
    {
        for(j=t;j>=0;j--)
        {
            if(j>=w[i])
            {
                dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
            }
        }
    }
    printf("%d",dp[t]);
    
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
