#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<numeric>
#define siz(x) int((x).size())
#define int long long
using std::cin;using std::cout;
struct __runtime{~__runtime(){cout.flush();std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
constexpr int kN=1e6+1,kM=502;
int n,a[kM][kM];
bool pr[kN];
std::basic_string<int>pt;
inline auto use_back(auto &x){auto y=x.back();x.pop_back();return y;}
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline int lcm(int x,int y){return x&&y?x/gcd(x,y)*y:x+y;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	if(n==2)return cout<<R"(4 7
23 10)",0;
	for(int i=2;i<kN;i++){
		if(!pr[i])pt+=i;
		for(int j:pt){
			if(i*j>=kN)break;else pr[i*j]=true;
			if(i%j==0)break;
		}
	}
	std::reverse(pt.begin(),pt.end());
	for(int i=2;i<=n*2;i+=2){
		int x=use_back(pt);
		for(int j=std::max(1ll,i-n);j<=std::min(n,i-1);j++)
			a[j][i-j]=x;
	}
	for(int i=(~n&1)+1-n;i<n;i+=2){
		int x=use_back(pt);
		for(int j=std::max(1ll,1-i);j<=std::min(n,n-i);j++)
			a[j][i+j]*=x;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(!a[i][j])a[i][j]=lcm(lcm(a[i-1][j],a[i][j-1]),lcm(a[i+1][j],a[i][j+1]))+1;
		cout<<a[i][j]<<" \n"[j==n];
	}
	return 0;
}