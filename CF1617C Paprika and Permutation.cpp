#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
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
constexpr int N=2e5+1;
int n,a[N];
bool vis[N];
std::basic_string<int>b;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;b.clear();
		memset(vis+1,0,sizeof(bool)*n);
		for(int i=1;i<=n;i++)cin>>a[i];
		std::sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)if(1<=a[i]&&a[i]<=n&&!vis[a[i]])vis[a[i]]=true;else b+=a[i];
		cout<<[]{
			int cnt=0;
			for(int i=1,j=0;i<=n;i++)if(!vis[i]){
				if(b[j++]<=i*2)return -1;
				cnt++;
			}
			return cnt;
		}()<<'\n';
	}
	return 0;
}