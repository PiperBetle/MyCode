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
constexpr int N=1e5+1;
int n,k,q,a[N],b[N],c[N],f[N];
loli m;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void merge(int x,int y){f[find(x)]=find(y);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>q;k=n;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=q;i++)if(cin>>a[i]>>b[i]>>c[i],!c[i]&&find(a[i])!=find(b[i]))merge(a[i],b[i]),k--;
	for(int i=1;i<=q;i++)if(c[i]&&find(a[i])==find(b[i]))return cout<<"No",0;
	if(m-n+k>1ll*k*(k-1)/2)return cout<<"No",0;
	if(!std::count(c+1,c+1+q,1))cout<<(k-1<=m-n+k?"Yes":"No");
	else cout<<(k>2&&k<=m-n+k?"Yes":"No");
	return 0;
}