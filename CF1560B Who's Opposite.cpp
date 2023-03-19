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
	int T,a,b,c;
	
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;
		if(a<b)swap(a,b);
		int n=a-b;
		n+=n;
		if((c>n)||(a>n)||(b>n))
		{
			cout<<-1<<endl;
			continue;
		}
		n/=2;
		if(c>n)cout<<c-n<<endl;
		else cout<<c+n<<endl;
	}
	
	return 0;
}
