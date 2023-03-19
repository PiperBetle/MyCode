#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=50001;
int n,a[kN],pre[kN+1],suf[kN+1];
bool vis[2*kN];
std::set<int,std::less<>>s1;
std::set<int,std::greater<>>s2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],vis[a[i]]=true;
	for(int i=1;i<=2*n;i++)if(!vis[i])s1.insert(i),s2.insert(i);
	for(int i=1;i<=n;i++)if(auto it=s1.lower_bound(a[i]);pre[i]=pre[i-1],it!=s1.end())s1.erase(it),pre[i]++;
	for(int i=n;i>=1;i--)if(auto it=s2.lower_bound(a[i]);suf[i]=suf[i+1],it!=s2.end())s2.erase(it),suf[i]++;
	int ans=suf[1];
	for(int i=1;i<=n;i++)ans=std::max(ans,pre[i]+suf[i+1]);
	cout<<ans;
	return 0;
}