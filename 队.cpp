#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

queue<int> s[2];
int x[2][2];

int main()
{
	int i,j,n;
	int n,t;
	
	while(scanf("%d",&a[i]))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			s[0].push(a[i]);
		}
		len=s[0].size();
		ans=0;
		if(len==1)
		{
			cout<<s.[0].front()<<endl;
		}
		else
		{
			x[0][0]=s[0].front();
			s[0].pop;
			x[0][1]=s[0].front();
			s[0].pop;
			ans+=x[0][0]+x[0][1];
			s[1].push(x[0][0])+x[0][1];
			if(s[0].empty)
			{
				cout<<s[1].front();
			}
			else
			{
				x[0][0]=s[0].front();
				x[1][0]=s[1].front();
				if(x[0][0]<x[1][0])
				{
					s[0].pop
				}
			}
			x[1][0]=s[1].front();
		}
	}
	
	
	return 0;
} 
