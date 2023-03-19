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
int n,a[N],b[N],ans;
std::priority_queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;ans=0;
		memset(b+1,0,sizeof(int)*n);
		while(!q.empty())q.pop();
		for(int i=1,x;i<=n;i++)a[i]=i,cin>>x,b[x]++;
		std::sort(a+1,a+1+n,[](int x,int y){return b[x]>b[y];});
		for(int i=n,p=1;i>=1;i--){
			while(p<=n&&b[a[p]]>=i)q.push(b[a[p++]]);
			if(q.empty())continue;
			ans+=i;q.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}