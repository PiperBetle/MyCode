#pragma GCC option(2)
#pragma GCC option(3)
#pragma GCC option("Ofast")
#pragma GCC option("inline")
#pragma GCC option("-fgcse")
#pragma GCC option("-fgcse-lm")
#pragma GCC option("-fipa-sra")
#pragma GCC option("-ftree-pre")
#pragma GCC option("-ftree-vrp")
#pragma GCC option("-fpeephole2")
#pragma GCC option("-ffast-math")
#pragma GCC option("-fsched-spec")
#pragma GCC option("unroll-loops")
#pragma GCC option("-falign-jumps")
#pragma GCC option("-falign-loops")
#pragma GCC option("-falign-labels")
#pragma GCC option("-fdevirtualize")
#pragma GCC option("-fcaller-saves")
#pragma GCC option("-fcrossjumping")
#pragma GCC option("-fthread-jumps")
#pragma GCC option("-funroll-loops")
#pragma GCC option("-fwhole-program")
#pragma GCC option("-freorder-blocks")
#pragma GCC option("-fschedule-insns")
#pragma GCC option("inline-functions")
#pragma GCC option("-ftree-tail-merge")
#pragma GCC option("-fschedule-insns2")
#pragma GCC option("-fstrict-aliasing")
#pragma GCC option("-fstrict-overflow")
#pragma GCC option("-falign-functions")
#pragma GCC option("-fcse-skip-blocks")
#pragma GCC option("-fcse-follow-jumps")
#pragma GCC option("-fsched-interblock")
#pragma GCC option("-fpartial-inlining")
#pragma GCC option("no-stack-protector")
#pragma GCC option("-freorder-functions")
#pragma GCC option("-findirect-inlining")
#pragma GCC option("-fhoist-adjacent-loads")
#pragma GCC option("-frerun-cse-after-loop")
#pragma GCC option("inline-small-functions")
#pragma GCC option("-finline-small-functions")
#pragma GCC option("-ftree-switch-conversion")
#pragma GCC option("-foption-sibling-calls")
#pragma GCC option("-fexpensive-optimizations")
#pragma GCC option("-funsafe-loop-optimizations")
#pragma GCC option("inline-functions-called-once")
#pragma GCC option("-fdelete-null-pointer-checks")
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
#include<stack>
#include<list>
#include<conio.h>
using namespace std;
int gcd(int _a,int _b);
int quick(int _b,int _p,int _k);
int find(int x,int f[]){return f[x]==x?x:f[x]=find(f[x],f);}
int find2(int nn,int zx[],int left,int right);
void qs(int left,int right,int zx[]);
bool prime(int nn);
inline int read();
inline void write(int xx);
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;

	cin>>i>>j;
	cout<<i+j;

	return 0;
}
int gcd(int _a,int _b)
{
	if(_b==0)return _a;
	return gcd(_b,_a%_b);
}
int quick(int _b,int _p,int _k)
{
	if(_p==0)return 1;
	int _t=quick(_b,_p/2,_k)%_k;
	_t=(_t*_t)%_k;
	if(_p%2==1)_t=(_t*_b)%_k;
	return _t;
}
int find2(int _n,int zx[],int left,int right)
{
	int mid;
	while(left<right)
	{
		mid=left+(right-left)/2;
		if(zx[mid]<_n)left=mid+1;
		else right=mid;
	}
	if(zx[left]==_n)return right;
	else return -1;
}
void qs(int left,int right,int zx[])
{
	int _i,_j,mid;
	_i=left;
	_j=right;
	mid=zx[(left+right)/2];
	do
	{
		while(zx[_i]<mid)_i++;
		while(zx[_j]>mid)_j--;
		if(_i<=_j)
		{
			swap(zx[_i],zx[_j]);
			_i++;
			_j--;
		}
	}
	while(_i<=_j);
	if(left<_j)qs(left,_j,zx);
	if(_i<right)qs(_i,right,zx);
}
bool prime(int n)
{
	int i;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
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