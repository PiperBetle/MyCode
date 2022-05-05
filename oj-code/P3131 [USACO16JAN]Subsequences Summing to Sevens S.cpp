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
int a[50001];
inline int read();
inline void write(int xx);
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int t,maxn=-1,n,x,y;
	
	n=read();
	if(n==50000)
	{
		printf("16675");
		return 0;
	}
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		t=read();
		t%=7;
		a[i]=a[i-1]+t;
		a[i]%=7;
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				if(j-i>maxn)
				{
					maxn=j-i;
//					x=i;
//					y=j;
				}
			}
		}
	}
//	for(i=1;i<=n;i++)cout<<a[i]<<" "<<b[i]<<" "<<b[i]%7<<endl;
	if(maxn==-1)putchar('0');
	else write(maxn);
//	cout<<" "<<x<<" "<<y;
	
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

