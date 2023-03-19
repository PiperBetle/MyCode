#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define big 715827882
#define BIG 715827882
using namespace std;
int len=0,a[1000008],j,k;
inline void get(int x)
{
	len++;
	a[len]=x;
	int j=len,k;
	while(x>1)
	{
		k=j>>1;
		if(a[j]>=a[k])return;
		swap(a[j],a[k]);
		j=k;
	}
}
inline int put()
{
	int t=a[1];
	a[1]=a[len];
	len--;
	j=1;
	while((j<<1)<=len)
	{
		k=j<<1;
		if((k<len)&&(a[k+1]<a[k]))k++;
		if(a[j]<=a[k])return t;
		swap(a[j],a[k]);
		j=k;
	}
	return t;
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
int main()
{
	int x,T;
	
	T=read();
	while(T--)
	{
		x=read();
		if(x==1)get(read());
		if(x==2)printf("%d\n",a[1]);
		if(x==3)put(); 
	} 
	
	return 0;
}
