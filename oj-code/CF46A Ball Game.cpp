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
	int n,m,t;
	
	cin>>n;
	t=1;
	for(i=1;i<n;i++)
	{
		t=((t+i-1)%n)+1;
		cout<<t<<' ';
	}
	
	return 0;
}
