
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

