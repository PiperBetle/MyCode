#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
constexpr int N=2e7+1;
std::string a,b;
int la,lb,z[N],p[N];
loli ans1,ans2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>a>>b;la=siz(a);lb=siz(b);
	a=' '+a;b=' '+b;z[1]=lb;
	for(int i=2,l=0,r=0;i<=lb;i++){
		if(i<r)z[i]=std::min(z[i-l+1],r-i);
		while(z[i]+i<=lb&&b[z[i]+i]==b[z[i]+1])z[i]++;
		if(z[i]+i>r)r=i+z[l=i];
	}
	for(int i=1,l=0,r=0;i<=la;i++){
		if(i<r)p[i]=std::min(z[i-l+1],r-i);
		while(p[i]+i<=la&&a[p[i]+i]==b[p[i]+1])p[i]++;
		if(p[i]+i>r)r=i+p[l=i];
	}
	for(int i=1;i<=lb;i++)ans1^=1ll*i*(z[i]+1);
	for(int i=1;i<=la;i++)ans2^=1ll*i*(p[i]+1);
	cout<<ans1<<'\n'<<ans2;
	return 0;
}