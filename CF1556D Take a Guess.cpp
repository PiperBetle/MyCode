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
int AND(int x,int y){(cout<<"and "<<x<<' '<<y<<'\n').flush();int t;cin>>t;return t;}
int OR(int x,int y){(cout<<"or "<<x<<' '<<y<<'\n').flush();int t;cin>>t;return t;}
constexpr int kN=1e4+1;
int n,k,a[kN],s[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	for(int i=2;i<=n;i++)s[i]=AND(i-1,i)+OR(i-1,i);
	a[1]=(s[2]-s[3]+AND(1,3)+OR(1,3))/2;
	for(int i=2;i<=n;i++)a[i]=s[i]-a[i-1];
	std::sort(a+1,a+1+n);
	cout<<"finish "<<a[k];
	return 0;
}