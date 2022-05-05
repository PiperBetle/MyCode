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
	int n,t;
	double sum=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		sum+=t;
	}
	printf("%.8f",sum/(double)n);
	
	return 0;
}

