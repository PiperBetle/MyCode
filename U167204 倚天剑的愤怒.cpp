#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define int loli
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1000001;
int n,m,a[kN];
std::basic_string<loli>b;
std::priority_queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(a[i]<0){q.push(a[i]);continue;}
		for(;!q.empty()&&a[i]>=-q.top();q.pop())a[i]+=q.top();
		if(q.empty())continue;
		int t=q.top()+a[i];
		q.pop();q.push(t);
	}
	for(;!q.empty();q.pop())b+=q.top();
	for(int i=1;i<siz(b);i++)b[i]+=b[i-1];
	std::reverse(all(b));b+=0ll;
	for(int h;m--;)cin>>h,cout<<std::lower_bound(b.begin(),b.end(),-h)-b.begin()<<'\n';
	return 0;
}