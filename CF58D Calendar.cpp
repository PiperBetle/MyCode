#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
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
constexpr int N=10001;
int n,m;
char c;
std::string a[N];
bool vis[N];
std::vector<std::string>b;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],m+=siz(a[i]);
	m/=n/2;std::sort(a+1,a+1+n);
	cin>>c;
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i]=true;
		for(int j=1;j<=n;j++)if(!vis[j]){
			if(siz(a[i])+siz(a[j])!=m)continue;
			vis[j]=true;
			b.push_back(std::min(a[i]+c+a[j],a[j]+c+a[i]));
			break;
		}
	}
	std::sort(all(b));
	for(cauto&i:b)cout<<i<<'\n';
	return 0;
}