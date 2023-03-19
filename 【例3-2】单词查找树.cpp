#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	string a[10001],t;
	int i,j,k,ans=0,n;
	
	i=1;
	while(cin>>a[i])
	{
		i++;
	}
	n=i-1;
	sort(a+1,a+n+1);
	ans=a[1].length()+1;
	for(i=2;i<=n;i++)
	{
		j=0;
		while((a[i-1][j]==a[i][j])&&(j<a[i-1].length()))
		{
			j++;
		}
		ans=ans+a[i].length()-j;
	}
	printf("%d",ans);
	
	return 0;
}
