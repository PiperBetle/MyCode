#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_map>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e6+1;
int n;
bool pr[kN];
std::basic_string<int>pt;
std::unordered_map<int,int>mp;
auto solve1(){
	std::basic_string<int>ans;
	for(auto[x,y]:mp)if(x==1)cont
}
auto solve2(){
	std::basic_string<int>ans;
	for(cauto&i:mp)for(cauto&j:mp)
		if(!pr[i.first+j.first])return (ans+=i.first)+=j.first;
	return ans+=mp.begin()->first;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=2;i<kN;i++){
		if(!pr[i])pt+=i;
		for(int j:pt){
			if(i*j>=kN)break;
			pr[i*j]=true;
			if(i%j==0)break;
		}
	}
	std::reverse(pt.begin(),pt.end());
	cin>>n;
	for(int i=1,t;i<=n;i++)cin>>t,mp[t]++;
	auto s1=solve1(),s2=solve2(),s=(siz(s1)<siz(s2)?s2:s1);
	cout<<siz(s)<<'\n';
	for(int i:s)cout<<i<<' ';
	return 0;
}