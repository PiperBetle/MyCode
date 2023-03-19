#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2e5+1;
int n,cnt[2];
bool c[N];
std::basic_string<int>g[N];
void dfs(int u,int fa){
	cnt[c[u]=!c[fa]]++;
	for(int v:g[u])if(v!=fa)dfs(v,u);
}
int skip(int &x){int y=x;x+=3;return y;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	dfs(1,0);
	int p1=1,p2=2,p3=3;
	if(cnt[0]>n/3&&cnt[1]>n/3){
		for(int i=1;i<=n;i++)
			if(c[i])cout<<skip(p1<=n?p1:p3)<<' ';
			else cout<<skip(p2<=n?p2:p3)<<' ';
	}else if(cnt[0]<=n/3){
		for(int i=1;i<=n;i++)
			if(c[i])cout<<skip(p1<=n?p1:(p2<=n?p2:p3))<<' ';
			else cout<<skip(p3)<<' ';
	}else{
		for(int i=1;i<=n;i++)
			if(!c[i])cout<<skip(p1<=n?p1:(p2<=n?p2:p3))<<' ';
			else cout<<skip(p3)<<' ';
	}
	return 0;
}