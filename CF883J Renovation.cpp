#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=100001;
int n,m,a[kN],ans;
pii p[kN];
std::priority_queue<int,std::vector<int>,std::greater<>>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;a[0]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>p[i].first;
	for(int i=1;i<=m;i++)cin>>p[i].second;
	std::sort(p+1,p+1+m);
	for(int i=n,j,k=1;i>=1;i=j){
		loli cnt=0;
		for(j=i;a[j]<=a[i];j--)cnt+=a[j];
		for(;k<=m&&p[k].first<=a[i];k++)q.push(p[k].second);
		while(!q.empty()){
			if(cnt>=q.top())ans++,cnt-=q.top(),q.pop();
			else{cnt=q.top()-cnt;q.pop();q.push(int(cnt));break;}
		}
	}
	cout<<ans;
	return 0;
}