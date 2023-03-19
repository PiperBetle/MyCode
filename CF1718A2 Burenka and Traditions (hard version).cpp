#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_map>
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
constexpr int N=100001;
struct easy_hash{
	size_t operator()(int x)const{return ((1919810ull*x)^19260817)+114514;}
};
std::unordered_map<int,int,easy_hash>mp;
int n,a[N],b[N],f[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]^a[i];
		mp.clear();mp[0]=0;
		for(int i=1;i<=n;i++){
			f[i]=f[i-1]+!!a[i];
			auto it=mp.find(b[i]);
			if(it==mp.end()){mp[b[i]]=i;continue;}
			f[i]=std::min(f[i],f[it->se]+i-it->se-1);
			it->se=i;
		}
		cout<<f[n]<<'\n';
	}	
	return 0;
}