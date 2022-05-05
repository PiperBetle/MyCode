#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
using std::cin;using std::cout;
constexpr int kN=2e5+7,inf=0x3f3f3f3f;
int f[2][kN];
std::deque<int>q;
inline void chkmin(auto &x,const auto &y){if(x<y)x=y;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,k,p=0;cin>>n>>k;
	memset(f[p],0x3f,sizeof f[p]);f[0][0]=0;
	while(k--){
		int l,r;cin>>l>>r;
		p=!p;memcpy(f[p],f[!p],sizeof f[p]);
		while(!q.empty())q.pop_front();
		for(int i=r;i>=0;i--){
			while(!q.empty()&&q.front()<l-i)q.pop_front();
			while(!q.empty()&&f[!p][r-i]<f[!p][q.back()])q.pop_back();
			q.emplace_back(r-i);
			f[p][i]=std::min(f[p][i],f[!p][q.front()]+1);
			// chkmin(f[p][i],f[!p][q.front()]+1);
		}
		while(!q.empty())q.pop_front();
		for(int i=0;i<=std::min(r,n);i++){
			while(!q.empty()&&q.front()<i-r+l)q.pop_front();
			while(!q.empty()&&f[!p][i]<f[!p][q.back()])q.pop_back();
			q.emplace_back(i);
			f[p][i]=std::min(f[p][i],f[!p][q.front()]+2);
			// chkmin(f[p][i],f[!p][q.front()]+2);
		}
	}
	if(f[p][n]==inf)cout<<"Hungry";
	else cout<<"Full\n"<<f[p][n];
	return 0;
}