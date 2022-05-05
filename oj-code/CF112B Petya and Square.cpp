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
int a[100007]={0};
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y;
	
	cin>>n>>x>>y;
	if((x==n/2||x==n/2+1)&&(y==n/2||y==n/2+1))cout<<"NO";
	else cout<<"YES";
	
	return 0;
}
