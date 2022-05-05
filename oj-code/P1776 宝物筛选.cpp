#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
struct tr{int c,w;};
std::vector<tr>a;
int f[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int c,w,t;
	
	cin>>n>>m;
	for(j=1;j<=n;j++)for(cin>>w>>c>>t,i=1;;t-=i,i<<=1)
		if(i>=t){a.emplace_back((tr){c*t,w*t});break;}
		else a.emplace_back((tr){c*i,w*i});
	for(auto&i:a)for(j=m;j>=i.c;j--)f[j]=max(f[j],f[j-i.c]+i.w);
	cout<<f[m];
	
	return 0;
}
