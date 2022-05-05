#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#define LEN 54
using namespace std;
inline int read();
inline char differ(int c)
{
	if(c=='a')return 's';
	return 'a';
}
char a[360][360]={0};
bool flag=0;  
int main()
{
//	freopen("i.in","r",stdin);
//	freopen("i.out","w",stdout);
	srand(time(NULL));
	int i,j,k;
	int T,t,n;
	
	T=read();
	while(T--)
	{
		n=read();
		for(i=1;i<=LEN;i++)a[0][i]='a';
		if(flag==0)
		{
			flag=1;
			for(j=1;j<=LEN;j++)putchar(a[0][j]);
		}
		else
		{
			putchar('\n');
			for(j=1;j<=LEN;j++)putchar(a[0][j]);
		}
		for(i=1;i<=n;i++)
		{
			t=read();
			for(j=1;j<=t;j++)a[i][j]=a[i-1][j];
			char er=a[i][t+1]=differ(a[i-1][t+1]);
			for(j=t+2;j<=LEN;j++)a[i][j]=er;
			putchar('\n');
			for(j=1;j<=LEN;j++)putchar(a[i][j]);
		}
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
