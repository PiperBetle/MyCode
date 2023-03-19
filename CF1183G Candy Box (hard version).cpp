#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int N=2e5+1;
int n,a[N],ans1,ans2;
pii b[N];
std::priority_queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;ans1=ans2=0;
		for(int i=1;i<=n;i++)b[i]={0,0};
		while(!q.empty())q.pop();
		for(int i=1,x,y;i<=n;i++)a[i]=i,cin>>x>>y,(y?b[x].se:b[x].fi)++;
		std::sort(a+1,a+1+n,[](int x,int y){return b[x].fi+b[x].se>b[y].fi+b[y].se;});
		for(int i=n,p=1;i>=1;i--){
			while(p<=n&&b[a[p]].fi+b[a[p]].se>=i)q.push(b[a[p++]].se);
			if(q.empty())continue;
			ans1+=i,ans2+=std::min(i,q.top());q.pop();
		}
		cout<<ans1<<' '<<ans2<<'\n';
	}
	return 0;
}