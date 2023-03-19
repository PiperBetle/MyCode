#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using std::cin;using std::cout;
struct island{int id,num;bool operator<(const island &t)const{return num<t.num;}}a[200007],now;
std::priority_queue<island>q;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n>>now.num;now.id=0;
	for(int i=1;i<=n;i++)cin>>a[i].id>>a[i].num;
	std::sort(a+1,a+1+n,[](const island &x,const island &y){return x.id<y.id;});
	for(int i=1;i<=n;i++){
		for(;;){
			if(now.num>=a[i].id-now.id)break;
			if(q.empty())return cout<<now.id+now.num,0;
			now.num+=q.top().num;q.pop();
		}
		now.num-=a[i].id-now.id;now.id=a[i].id;
		q.push(a[i]);
	}
	while(!q.empty())now.num+=q.top().num,q.pop();
	cout<<now.id+now.num;
	return 0;
}