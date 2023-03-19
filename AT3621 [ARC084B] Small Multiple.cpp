#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
using std::cin;using std::cout;
using pii=std::pair<int,int>;
std::deque<pii>q;
bool vis[100007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int k;cin>>k;
	for(q.emplace_front(1,1),vis[1]=true;!q.empty();){
		auto[x,w]=q.front();q.pop_front();
		if(!x)return cout<<w,0;
		if(!vis[10*x%k])q.emplace_front(10*x%k,w),vis[10*x%k]=true;
		if(!vis[(x+1)%k])q.emplace_back((x+1)%k,w+1);
	}
	return 0;
}