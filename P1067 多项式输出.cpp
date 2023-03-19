#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[101],n,m,i,j,k,sum=0,t,flag=0;
	
	cin>>n;
	for(i=n;i>=0;i--)
	{
		scanf("%d",&t);
		if(t!=0)
		{
			if(t<0)
			{
				printf("-");
				t=-t;
				flag=1;
			}
			else
			{
				if(flag) 
					printf("+");
				flag=1;
			}
			if(t==1)
			{
				if(i==1)
				{
					printf("x");
				}
				else
				{
					if(i==0)
					{
						printf("1");
					}
					else
					{
						printf("x^%d",i);
					}
				}
			}
			else
			{
				if(i==1)
				{
					printf("%dx",t);
				}
				else
				{
					if(i==0)
					{
						printf("%d",t);
					}
					else
					{
						printf("%dx^%d",t,i);
					}
				}
			}
		}
	}
	
	return 0;
}

