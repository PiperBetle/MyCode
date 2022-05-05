#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	long long a,b,c;
	
	cin>>a>>b>>c;
	a=a*a;
	b=b*c;
	if(a>b)cout<<"Alice";
	else cout<<"Bob";
	
	return 0;
}
