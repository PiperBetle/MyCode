#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<numeric>
#include<cmath>
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
constexpr int N=1e5+1,M=5001;
int n,m,a[M],pre[M];
namespace pbds=__gnu_pbds;
std::basic_string<int>pt;
pbds::gp_hash_table<int,pbds::null_type>s;
bool pr[N];
inline int mif(int x){
	for(int i:pt){
		if(i*i>x)return x;
		if(x%i==0)return i;
	}
	return x;
}
inline int calc(int x){
	static pbds::gp_hash_table<int,int>b;
	if(x==1)return 0;
	if(b.find(x)!=b.end())return b[x];
	int t=mif(x);
	return b[x]=calc(x/t)+(s.find(t)!=s.end()?-1:1);
}
signed main(){
//	freopen("cup.in","r",stdin);
//	freopen("cup.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=2;i<N;i++){
		if(!pr[i])pt+=i;
		for(int j:pt){
			if(i*j>=N)break;
			pr[i*j]=true;
			if(i%j==0)break;
		}
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,x;i<=m;i++)cin>>x,s.insert(x);
	pre[1]=a[1];for(int i=2;i<=n;i++)pre[i]=std::__gcd(pre[i-1],a[i]);
	int ans=0;
	for(int i=n,g=1;i>=1;i--){
		int now=pre[i]/g;
		if(now>1&&calc(now)<0)g*=now;
		ans+=calc(a[i]/g);
	}
	cout<<ans;
	return 0;
}