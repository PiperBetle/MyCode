#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
using std::cin;using std::cout;
priority_queue<int,std::less<int>>max_q;
priority_queue<int,std::greater<int>>min_q;
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,T;
	cin>>T;
	while(T--){
		cin>>n;cout<<n<<' ';
		cin>>n;cout<<(n>>1)+1<<'\n';
		for(i=1;i<=n;i++){
			cin>>m;
			if(min_q.empty()||m>min_q.top())min_q.push(m);else max_q.push(m);
			if((i&1)&&max_q.size()>min_q.size())min_q.push(max_q.top()),max_q.pop();
			else if(!(i&1)&&max_q.size()<min_q.size())max_q.push(min_q.top()),min_q.pop();
			if(i&1)cout<<min_q.top()<<" \n"[((i+1)>>1)%10==0||i==n];
		}
		max_q.clear();min_q.clear();
	}
	return 0;
}