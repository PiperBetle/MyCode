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
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e4+1;
int n,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	if(n==1)return cout<<"! 1",0;
	for(int i=2,j=1,x,y;i<=n;i++){
		(cout<<"? "<<j<<' '<<i<<"\n? "<<i<<' '<<j<<'\n').flush();
		cin>>x>>y;
		if(x<y)a[i]=y;else a[j]=x,j=i;
		if(i==n)a[j]=n;
	}
	cout<<'!';
	for(int i=1;i<=n;i++)cout<<' '<<a[i];
	return 0;
}