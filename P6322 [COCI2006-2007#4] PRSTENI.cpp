#include<cstdio>
#include<iostream>
using namespace std;
inline int read();
inline int gcd(int _a,int _b)
{
    while(_b^=_a^=_b^=_a%=_b);
    return _a;
}
int a[1001];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,jw;
	
    n=read();
    for(i=1;i<=n;i++)a[i]=read();
    for(i=2;i<=n;i++)printf("%d/%d\n",a[1]/gcd(a[1],a[i]),a[i]/gcd(a[1],a[i]));
	
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
