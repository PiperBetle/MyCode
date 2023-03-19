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
struct cmp1{bool operator()(const pii &x,const pii &y)const{return x.fi==y.fi?x.se<y.se:x.fi>y.fi;}};
struct cmp2{bool operator()(const pii &x,const pii &y)const{return x.se==y.se?x.fi<y.fi:x.se<y.se;}};
constexpr int N=1e5+1;
std::multiset<pii,cmp1>s1;
std::multiset<pii,cmp2>s2;
int n;
loli ans1,ans2;
pii a[N];
inline int to(int &x,const pii &y){
	int k=0;
	if(x<y.fi)k=y.fi-x,x=y.fi;
	else if(x>y.se)k=x-y.se,x=y.se;
	return k;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se;
	for(int i=1;i<=n;i++)s1.insert(a[i]),s2.insert(a[i]);
	for(int i=1,p=0;i<=n;i++){
		if(i&1){
			pii v=*s2.begin();
			ans1+=to(p,v);
			s1.erase(s1.find(v));
			s2.erase(s2.find(v));
		}else{
			pii v=*s1.begin();
			ans1+=to(p,v);
			s1.erase(s1.find(v));
			s2.erase(s2.find(v));
		}
		if(i==n)ans1+=abs(p);
	}
	for(int i=1;i<=n;i++)s1.insert(a[i]),s2.insert(a[i]);
	for(int i=1,p=0;i<=n;i++){
		if(~i&1){
			pii v=*s2.begin();
			ans2+=to(p,v);
			s1.erase(s1.find(v));
			s2.erase(s2.find(v));
		}else{
			pii v=*s1.begin();
			ans2+=to(p,v);
			s1.erase(s1.find(v));
			s2.erase(s2.find(v));
		}
		if(i==n)ans2+=abs(p);
	}
	cout<<std::max(ans1,ans2);
	return 0;
}