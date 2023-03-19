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
	int T,t;
	
	for(;;)
	{
		cin>>t;
		if(t==0)return 0;
		if(t%2==0)puts("Alice");
		else puts("Bob");
	}
	
	return 0;
}
