#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<list>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1,kM=1e6+1;
std::list<int>s[kM];
int n,m,ans,c[kN],fa[kM];
void merge(int &x,int &y){
	if(siz(s[x])>siz(s[y]))std::swap(x,y);
	if(x==y||!siz(s[x]))return;
	for(int i:s[x])ans-=(c[i-1]==y)+(c[i+1]==y);
	for(int i:s[x])c[i]=y;
	s[y].splice(s[y].end(),s[x]);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i],fa[c[i]]=c[i],ans+=c[i]!=c[i-1],s[c[i]].push_back(i);
	for(int x,y;m--;){
		cin>>x;
		if(x==2){cout<<ans<<'\n';continue;}
		else cin>>x>>y,merge(fa[x],fa[y]);
	}
	return 0;
}