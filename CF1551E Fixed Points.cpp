#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2001;
int n,m,f[kN][kN],a[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			memset(f[i],0,sizeof(int)*(n+1));
			f[i][0]=f[i-1][0]+(a[i]==i);
			for(int j=1;j<=i;j++)
				f[i][j]=std::max(f[i-1][j-1],f[i-1][j]+(a[i]==i-j));
		}
		cout<<[]{
			for(int i=0;i<=n;i++)
				if(f[n][i]>=m)return i;
			return -1;
		}()<<'\n';
	}
	return 0;
}