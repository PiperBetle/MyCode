#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[101],flag=0,doing,i,j,m,n,t=0;
	
	for(i=0;i<=100;i++)a[i]=0;
	cin>>n>>m;
	for(doing=1;doing<=n;doing++)
	{
		for(j=1;j<=m;j++)
		{
			flag++;
			flag%=n;
			if(flag==0)flag=n;
			if(a[flag]==-1)
			{
				j--;
				continue;
			}
		}
		if(t==1)
		{
			cout<<" "<<flag;
		}
		else
		{
			t=1;
			cout<<flag;
		}
		a[flag]=-1;
	}

	return 0;
}
