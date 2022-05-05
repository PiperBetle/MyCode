#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int max(int x,int y){return x>y?x:y;}
struct very_long
{
	int data[57];
	very_long()
	{
		memset(data,0,sizeof data);
	}
	very_long(int x)
	{
		memset(data,0,sizeof data);
		if(x!=0)
		{
			int k=0;
			while(x)
			{
				k++;
				data[k]=x%10000000;
				x/=10000000;
			}
			data[0]=k;
		}
	}
	friend very_long operator +(very_long a,very_long b)
	{
		a.data[0]=max(a.data[0],b.data[0])+1;
		for(int i=1;i<=a.data[0];i++)
		{
			a.data[i]+=b.data[i];
			if(a.data[i]>=10000000)
			{
				a.data[i+1]++;
				a.data[i]-=10000000;
			}
		}
		while(a.data[0]>0&&a.data[a.data[0]]==0)
			a.data[0]--;
		return a;
	}
};
very_long a[607][607];
void pr(very_long x)
{
	for(int i=x.data[0];i>=1;i--)
	{
		if(i!=x.data[0])
		{
            if(x.data[i]<1000000)
                printf("0");
            if(x.data[i]<100000)
                printf("0");
            if(x.data[i]<10000)
                printf("0");
            if(x.data[i]<1000)
                printf("0");
            if(x.data[i]<100)
                printf("0");
            if(x.data[i]<10)
                printf("0");
		}
		printf("%d",x.data[i]);
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=0,w;
	
	scanf("%d%d",&k,&w);
	int l=(w-1)/k+1;
	for(i=1;i<=(1<<k)+1;i++)
	{
		a[i][1]=a[i][i]=1;
		for(j=2;j<i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
	very_long sum=0;
	for(i=2;i<l;i++)
		sum=sum+a[(1<<k)][i+1];
	w=(w-1)%k+1;
	for(i=1;i<(1<<w);i++)
		sum=sum+a[(1<<k)-i][l];
	pr(sum);
	
    return 0;
}
