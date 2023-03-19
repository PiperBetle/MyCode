#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
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
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		int A=0,B=0,sum=0,cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1,j=n;i<=j;){
			int k=0;
			for(;i<=j&&k<=sum;A+=a[i],k+=a[i++]);
			sum=k;k=0;cnt++;
			if(i>j)break;
			for(;i<=j&&k<=sum;B+=a[j],k+=a[j--]);
			sum=k;cnt++;
			if(i>j)break;
		}
		cout<<cnt<<' '<<A<<' '<<B<<'\n';
	}
	return 0;
}