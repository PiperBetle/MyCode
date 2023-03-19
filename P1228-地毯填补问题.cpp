#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
void play(int x1,int y1,int n,int x2,int y2)
{
	n--;
	if(n<0)
		return;
	if(x1<=x2&&x2<x1+(1<<n)&&y1<=y2&&y2<y1+(1<<n))
	{
		printf("%d %d 1\n",x1+(1<<n),y1+(1<<n));
		play(x1,y1,n,x2,y2);
		play(x1,y1+(1<<n),n,x1+(1<<n)-1,y1+(1<<n));//2
		play(x1+(1<<n),y1,n,x1+(1<<n),y1+(1<<n)-1);//3
		play(x1+(1<<n),y1+(1<<n),n,x1+(1<<n),y1+(1<<n));//4
	}
	if(x1<=x2&&x2<x1+(1<<n)&&y1+(1<<n)<=y2&&y2<y1+(1<<(n+1)))
	{
		printf("%d %d 2\n",x1+(1<<n),y1+(1<<n)-1);
		play(x1,y1+(1<<n),n,x2,y2);
		play(x1,y1,n,x1+(1<<n)-1,y1+(1<<n)-1);//1
		play(x1+(1<<n),y1,n,x1+(1<<n),y1+(1<<n)-1);//3
		play(x1+(1<<n),y1+(1<<n),n,x1+(1<<n),y1+(1<<n));//4
	}
	if(x1+(1<<n)<=x2&&x2<x1+(1<<(n+1))&&y1<=y2&&y2<y1+(1<<n))
	{
		printf("%d %d 3\n",x1+(1<<n)-1,y1+(1<<n));
		play(x1+(1<<n),y1,n,x2,y2);
		play(x1,y1,n,x1+(1<<n)-1,y1+(1<<n)-1);//1
		play(x1,y1+(1<<n),n,x1+(1<<n)-1,y1+(1<<n));//2
		play(x1+(1<<n),y1+(1<<n),n,x1+(1<<n),y1+(1<<n));//4
	}
	if(x1+(1<<n)<=x2&&x2<x1+(1<<(n+1))&&y1+(1<<n)<=y2&&y2<y1+(1<<(n+1)))
	{
		printf("%d %d 4\n",x1+(1<<n)-1,y1+(1<<n)-1);
		play(x1+(1<<n),y1+(1<<n),n,x2,y2);
		play(x1,y1,n,x1+(1<<n)-1,y1+(1<<n)-1);//1
		play(x1,y1+(1<<n),n,x1+(1<<n)-1,y1+(1<<n));//2
		play(x1+(1<<n),y1,n,x1+(1<<n),y1+(1<<n)-1);//3
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,x,y;
	
	scanf("%d%d%d",&n,&x,&y);
	play(1,1,n,x,y);
	
    return 0;
}
