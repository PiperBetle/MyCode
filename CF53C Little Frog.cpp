#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			cout<<i/2+1<<" ";
		}
		else
		{
			cout<<n-i/2+1<<" ";
		}
	}
	
	return 0;
}

