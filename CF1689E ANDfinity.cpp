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
constexpr int N=2001;
int n,m,a[N],f[N],ans;
std::basic_string<int>b;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void merge(int x,int y){if((x=find(x))!=(y=find(y)))f[x]=y;}
inline int lowbit(int x){return x&-x;}
bool check(){
	for(int i=1;i<=n;i++)f[i]=i;
	for(int k=0;k<30;k++){
		for(int i=1,p=0;i<=n;i++)if(a[i]&(1<<k)){
			if(p)merge(p,i);else p=i;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(find(i)==i&&++cnt>1)return false;
	return true;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;ans=0;
		for(int i=1;i<=n;i++)if(cin>>a[i],!a[i])ans++,a[i]=1;
		if(check())goto skip;
		for(int i=1;i<=n;i++){
			int k=a[i];
			a[i]=k-1;if(check()&&++ans)goto skip;
			a[i]=k+1;if(check()&&++ans)goto skip;
			a[i]=k;
		}
		m=0;b.clear();
		for(int i=1;i<=n;i++)m=std::max(m,lowbit(a[i]));
		for(int i=1;i<=n;i++)if(m==lowbit(a[i]))b+=i;
		ans+=2;a[b.front()]++,a[b.back()]--;
		skip:
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}