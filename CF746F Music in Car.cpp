#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1;
int n,k,m,w[kN],c[kN];
std::multiset<int>u0,u1;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	int val=0,cost=0,ans=0;
	for(int l=1,r=1;r<=n;r++){
		cost+=(c[r]+1)/2;
		val+=w[r];
		u1.insert(c[r]);
		if(siz(u1)>m){
			u0.insert(*u1.begin());
			cost+=*u1.begin()/2;
			u1.erase(u1.begin());
		}
		for(;l<=r&&cost>k;val-=w[l++]){
			if(c[l]>=*u1.begin()){
				cost-=(c[l]+1)/2;
				u1.erase(u1.find(c[l]));
				if(!u0.empty()){
					u1.insert(*u0.rbegin());
					cost-=*u0.rbegin()/2;
					u0.erase(u0.find(*u0.rbegin()));
				}
			}else{
				u0.erase(u0.find(c[l]));
				cost-=c[l];
			}
		}
		ans=std::max(ans,val);
	}
	cout<<ans;
	return 0;
}