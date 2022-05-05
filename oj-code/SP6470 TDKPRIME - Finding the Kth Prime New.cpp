#pragma GCC optimize(2)
#include<cstdio>
#include<iostream>
bool pr[100000007];
int pt[10000007],len;
inline int read()
{
	int w=0,c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=(w<<1)+(w<<3)+(c^48);
	return w;
}
inline void write(int x)
{
    if(x>9)write(x/10);
    putchar(x%10+48);
}
int main()
{
	int i,j,k;
	int n=read(),m;
	
	for(i=2;i<=100000000;i++)
	{
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=100000000;j++)
		{
			pr[i*pt[j]]=1;
			if(i%pt[j]==0)break;
		} 
	}
	while(n--)write(pt[read()]),putchar('\n');
	
	return 0;
}