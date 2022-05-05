#include<cstdio>
#define MOD 1000000000
using namespace std;
inline int read();
inline void write(int xx);
int x1,x2,y1,y2;
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int abs(int n)
{
	if(n>0)return n;
	return -n;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	int t=read();
	while(t--)
	{
		x1=read();
		y1=read();
		x2=read();
		y2=read();
		if(gcd(abs(x1-x2),abs(y1-y2))==1)puts("no");
		else puts("yes");
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

