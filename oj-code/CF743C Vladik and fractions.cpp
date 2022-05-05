#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
#define int long long
using namespace std;
signed main()
{
//	freopen("toy.in","r",stdin);
//	freopen("toy.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y;
	
	cin>>n;
	if(n==1)
	{
		cout<<-1;
		return 0;
	}
	cout<<n<<" "<<n+1<<" "<<n*(n+1);
	
	return 0;
}
