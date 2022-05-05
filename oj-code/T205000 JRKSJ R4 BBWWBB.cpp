#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int i,j,k;
	int n,m,ans;

	cin>>n;
	for(i=1;i<=n;i++)
	{
		char cc;
		int a,b,c,d,e,f;
		cin>>cc>>a>>b>>c>>d>>e>>f;
		if(cc=='W'&&((c==b+1)^(e==d+1)))
			if(c==b+1)puts(a==b-1?"No":"Yes");
			else puts(e==f-1?"No":"Yes");
		else puts("No");
	}

	return 0;
}