#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ext/pb_ds/priority_queue.hpp>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1000001;
__gnu_pbds::priority_queue<int>q;
int n,a[kN],b[kN];
loli ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;for(int i=1;i<=n;i++){
		cin>>b[i];q.push(b[i]-=i);
		if(b[i]<q.top())q.pop(),q.push(b[i]);
		a[i]=q.top();
	}
	for(int i=n-1;i>=1;i--)a[i]=std::min(a[i],a[i+1]);
	for(int i=1;i<=n;i++)ans+=abs(a[i]-b[i]);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)cout<<a[i]+i<<' ';
	return 0;
}