#include<cstdio>
using namespace std;
int a[10091],len,n,ans=0;
inline int read();
inline void write(int xx);
void put(int t)
{
	len++;
	a[len]=t;
	int j=len,k;
	while(j>1)
	{
		k=j>>1;
		if(a[j]>=a[k])break;
		a[j]=a[j]^a[k];
		a[k]=a[j]^a[k];
		a[j]=a[j]^a[k];
		j=k;
	}
}
int get()
{
	int ret,j=1,k;
	ret=a[1];
	a[1]=a[len];
	len--;
	while((j<<1)<=len)
	{
		k=j<<1;
		if(k<len&&a[k+1]<a[k])k++;
		if(a[j]<=a[k])return ret;
		a[j]=a[j]^a[k];
		a[k]=a[j]^a[k];
		a[j]=a[j]^a[k];
		j=k;
	}
	return ret;
}
int fx(int p,int x)
{
	return f[p][1]*x*x+f[p][2]*x+f[p][3];
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	int i,j,k,t;
	
	n=read();
	m=read();
	for(i=1;i<=n;i++)for(j=1;j<=3;j++)a[i][j]=read();
	i=1;
	while(i*n<n+m)
	{
		for(j=1;j<=n;j++)put(fx(j,i));
		i++;
	}
	while(r)
	{
		
	}
	
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
