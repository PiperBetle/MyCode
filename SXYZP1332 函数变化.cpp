#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>m;
	if(min_q.empty()||m>min_q.top())min_q.push(m);else max_q.push(m);
	if((i&1)&&max_q.size()>min_q.size())min_q.push(max_q.top()),max_q.pop();
	else if(!(i&1)&&max_q.size()<min_q.size())max_q.push(min_q.top()),min_q.pop();
	if(i&1)cout<<min_q.top()<<" \n"[((i+1)>>1)%10==0||i==n];
	return 0;
}