#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,j,k,ans,t,go=0,flag=0,qw;
	
	cin>>n;
	qw=n*n;
	while(ans<qw)
	{
		scanf("%d",&t);
		ans+=t;
		for(i=1;i<=t;++i)
		{
			if(flag==0)cout<<0;
			else cout<<1;
			++go;
			if(go==n)
			{
				cout<<endl;
				go=0;
			}
		}
		flag=1-flag;
	}
	
    return 0;
}
