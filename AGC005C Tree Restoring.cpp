#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<map>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
int n;
std::map<int,int>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,x;i<=n;i++)cin>>x,s[x]++;
	if(s.rbegin()->fi&1&&s.begin()->se!=2)return cout<<"Impossible",0;
	if(~s.rbegin()->fi&1&&s.begin()->se!=1)return cout<<"Impossible",0;
	if(s.begin()->fi!=(s.rbegin()->fi+1)/2)return cout<<"Impossible",0;
	for(auto it=++s.begin();it!=s.end();++it)if(it->se<2||it->fi-prev(it)->fi!=1)return cout<<"Impossible",0;
	cout<<"Possible";
	return 0;
}