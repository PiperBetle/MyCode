#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using std::cin;using std::cout;
struct flower{int w,c;bool operator<(const flower &t)const{return c<t.c;}};
std::set<flower>s;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int x,y,t;;){
		cin>>t;switch(t){
		case 1:cin>>x>>y;s.emplace(x,y);break;
		case 2:if(!s.empty())s.erase(--s.end());break;
		case 3:if(!s.empty())s.erase(s.begin());break;
		case -1:
			int ans1=0,ans2=0;
			for(auto it:s)ans1+=it.w,ans2+=it.c;
			return cout<<ans1<<' '<<ans2,0;
		}
	}
	return 0;
}