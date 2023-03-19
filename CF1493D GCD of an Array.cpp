#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
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
constexpr int N=200001,MOD=1e9+7;
std::multiset<int>s[N];
int n,m,a[N],mif[N],cnt[N],ans=1;
bool pr[N];
std::basic_string<int>pt;
void updata(int x,int k){
	while(k!=1){
		if(!s[mif[k]].contains(x))cnt[mif[k]]++;
		s[mif[k]].insert(x);
		if(cnt[mif[k]]==n){
			cnt[mif[k]]=0;
			for(int i=1;i<=n;i++){
				s[mif[k]].erase(s[mif[k]].find(i));
				if(s[mif[k]].contains(i))cnt[mif[k]]++;
			}
			ans=int(1ll*ans*mif[k]%MOD);
		}
		k/=mif[k];
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=2;i<N;i++){
		if(!pr[i])pt+=i,mif[i]=i;
		for(int j:pt){
			if(i*j>=N)break;
			pr[i*j]=true,mif[i*j]=j;
			if(i%j==0)break;
		}
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],updata(i,a[i]);
	for(int x,k;m--;){
		cin>>x>>k;
		updata(x,k);
		cout<<ans<<'\n';
	}
	return 0;
}