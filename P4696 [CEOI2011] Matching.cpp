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
constexpr int N=1e6+1;
int n,m,p[N],a[N],cnt[N],kmp[N];
std::basic_string<int>b,ans;
struct{
	int d[N]={};
	void clear(){memset(d+1,0,sizeof(int)*m);}
	void updata(int x,int k){for(;x<=m;x+=x&-x)d[x]+=k;}
	int query(int x){int k=0;for(;x;x-=x&-x)k+=d[x];return k;}
}tr;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;cnt[n+1]=-1;
	for(int i=1,x;i<=n;i++)cin>>x,p[x]=i;
	b.reserve(n);for(int i=1;i<=m;i++)cin>>a[i],b+=a[i];std::sort(all(b));
	for(int i=1;i<=m;i++)a[i]=int(std::lower_bound(all(b),a[i])-b.begin())+1;
	for(int i=1;i<=n;i++)cnt[i]=tr.query(p[i]),tr.updata(p[i],1);
	tr.clear();
	for(int i=2,j=0;i<=n;i++){
		while(j&&tr.query(p[i])!=cnt[j+1]){
			for(int k=i-j;k<i-kmp[j];k++)tr.updata(p[k],-1);
			j=kmp[j];
		}
		if(tr.query(p[i])==cnt[j+1])j++,tr.updata(p[i],1);
		kmp[i]=j;
	}
	tr.clear();
	for(int i=1,j=0;i<=m;i++){
		while(j&&tr.query(a[i])!=cnt[j+1]){
			for(int k=i-j;k<i-kmp[j];k++)tr.updata(a[k],-1);
			j=kmp[j];
		}
		if(tr.query(a[i])==cnt[j+1])j++,tr.updata(a[i],1);
		if(j==n)ans+=i-n+1;
	}
	cout<<siz(ans)<<'\n';
	for(int i:ans)cout<<i<<' ';
	return 0;
}