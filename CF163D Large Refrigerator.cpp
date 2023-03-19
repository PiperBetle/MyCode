#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=100;
constexpr loli inf=0x3f3f3f3f3f3f3f3f;
constexpr venti operator""_vt(unsigned long long x){return venti(x);}
int n;
struct:std::basic_string<loli>{int cnt;}a[kN];
loli ans,A,B,C,V;
void dfs_b(int now,loli _a,loli _b){
	if(1_vt*_a*_b*_b>V)return;
	if(now==n+1){if(loli _c=V/(_a*_b);_a*_b+_a*_c+_b*_c<ans)ans=_a*_b+_a*_c+_b*_c,A=_a,B=_b,C=_c;}
	else for(int i=a[now].cnt;i>=0;i--)a[now].cnt-=i,dfs_b(now+1,_a,_b*a[now][i]),a[now].cnt+=i;
}
void dfs_a(int now,loli _a){
	if(1_vt*_a*_a*_a>V)return;
	if(now==n+1){if(loli _bc=V/_a;ans>2*_a*sqrtl(_bc)+_bc)dfs_b(1,_a,1);}
	else for(int i=a[now].cnt;i>=0;i--)a[now].cnt-=i,dfs_a(now+1,_a*a[now][i]),a[now].cnt+=i;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;ans=inf;V=1;
		for(int i=1;i<=n;i++){
			a[i].resize(2);cin>>a[i][1]>>a[i].cnt;
			a[i].resize(a[i].cnt+1);a[i][0]=1;
			for(int j=2;j<siz(a[i]);j++)a[i][j]=a[i][j-1]*a[i][1];
			V*=a[i].back();
		}
		dfs_a(1,1);
		cout<<2*ans<<' '<<A<<' '<<B<<' '<<C<<'\n';
	}
	return 0;
}