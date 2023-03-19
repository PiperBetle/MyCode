#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using std::cin;using std::cout;
#define int long long
std::priority_queue<int,std::vector<int>,std::greater<int>>q;
struct beauty{int data,cnt;bool operator<(const beauty &t){return data>t.data;}}a[100007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m,ans=0;cin>>n>>m;
	for(int i=1,t;i<=n;i++)cin>>t,q.emplace(t);
	for(int i=1;i<=m;i++)cin>>a[i].cnt>>a[i].data;
	std::sort(a+1,a+1+m);
	for(int i=1;i<=n;i++){
		if(q.top()>=a[i].data)break;
		for(int j=1;j<=a[i].cnt;j++){
			if(q.top()>=a[i].data)break;
			q.pop();q.emplace(a[i].data);
		}
	}
	while(!q.empty())ans+=q.top(),q.pop();
	cout<<ans;
	return 0;
}