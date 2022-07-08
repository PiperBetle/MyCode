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
constexpr int kN=2e5+1;
int n,a[kN];
std::string s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>s;s=' '+s;
		for(int i=1;i<=n;i++)a[i]=n+1-i;
		for(int i=1,j=1;i<n;i=j+1){
			for(j=i;s[j]=='<';j++);
			std::reverse(a+i,a+1+j);
		}
		for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
		for(int i=1;i<=n;i++)a[i]=i;
		for(int i=1,j=1;i<n;i=j+1){
			for(j=i;s[j]=='>';j++);
			std::reverse(a+i,a+1+j);
		}
		for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
	}
	return 0;
}