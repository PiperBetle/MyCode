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
using namespace std;
int find2(int nn,int zx[],int left,int right);
void qs(int left,int right,int zx[]);
bool prime(int nn);
inline int read();
inline void write(int xx);
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int a[100001],b[100001];
	int n,m;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)a[i]=read();
	for(i=1;i<=m;i++)b[i]=read();
	qs(1,m,b);
	for(i=1;i<=n;i++)
	{
		if(find2(a[i],b,1,m)!=-1)
		{
			write(a[i]);
			putchar(' ');
		}
	}
	
	return 0;
}
int find2(int nn,int zx[],int left,int right)
{
	int mid;
	while(left<right)
	{
		mid=left+(right-left)/2;
		if(zx[mid]<nn)left=mid+1;
		else right=mid;
	}
	if(zx[left]==nn)return right;
	else return -1;
}
void qs(int left,int right,int zx[])
{
	int ii,jj,mid;
	ii=left;
	jj=right;
	mid=zx[(left+right)/2];
	do
	{
		while(zx[ii]<mid)ii++;
		while(zx[jj]>mid)jj--;
		if(ii<=jj)
		{
			swap(zx[ii],zx[jj]);
			ii++;
			jj--;
		}
	}
	while(ii<=jj);
	if(left<jj)qs(left,jj,zx);
	if(ii<right)qs(ii,right,zx);
}
bool prime(int nn)
{
	int ii;
	for(int ii=2;ii*ii<=nn;ii++)
	{
		if(nn%ii==0)
		{
			return 0;
		}
	}
	return 1;
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
