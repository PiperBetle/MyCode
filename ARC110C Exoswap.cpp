#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1;
int n,m,tr[kN],a[kN],p[kN];
loli sum;
inline void updata(int x,int k){for(;x<=n;x+=x&-x)tr[x]+=k;}
inline loli query(int x){loli k=0;for(;x;x-=x&-x)k+=tr[x];return k;}
std::basic_string<int>ans;
signed main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;m=n;
	for(int i=1;i<=n;i++)cin>>a[i],p[a[i]]=i;
	for(int i=n;i>=1;i--)sum+=query(a[i]-1),updata(a[i],1);
	if(sum!=n-1)return cout<<"-1",0;
	for(int i=1;i<n;i++){
		while(a[m]==m)m--;
		ans+=p[m];
		std::swap(a[p[m]],a[p[m]+1]);
		p[m]++,p[a[p[m]+1]]--;
	}
	auto res=ans;
	std::sort(all(res));
	res.erase(std::unique(all(res)),res.end());
	if(siz(res)!=siz(ans))return cout<<"-1",0; 
	for(int i:ans)cout<<i<<'\n';
	return 0;
}