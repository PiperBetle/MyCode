#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#define LEN 54
using namespace std;
inline int read();
int a[4][4];
int main()
{
//	freopen("i.in","r",stdin);
//	freopen("i.out","w",stdout);
	srand(time(NULL));
	int i,j,k;
	int T,t,n;
	int x=read(),y=read(),z=read();
	
//	x y _
//	_ z _
//	_ _ _
	a[1][1]=x;
	a[1][2]=y;
	a[2][2]=z;
	t=3*z;
	a[1][3]=t-a[1][1]-a[1][2];
	a[3][1]=t-a[1][3]-a[2][2];
	a[2][1]=t-a[1][1]-a[3][1];
	a[2][3]=t-a[2][1]-a[2][2];
	a[3][2]=t-a[1][2]-a[2][2];
	a[3][3]=t-a[1][1]-a[2][2];
	printf("%d %d %d\n%d %d %d\n%d %d %d",a[1][1],a[1][2],a[1][3],a[2][1],a[2][2],a[2][3],a[3][1],a[3][2],a[3][3]);
	
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
