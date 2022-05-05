#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int a,b,c;
	
	cin>>c;
	for(i=1;i<=c;i++)
	{
		for(j=i;j<=c;j++)
		{
			if(i*i+j*j==c*c)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	
	return 0;
}
