#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<random>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1,kM=1e6+1;
bool pr[kM];
std::basic_string<int>pt;
std::set<loli>fc;
loli a[kN];
int n;
void solve(loli x){
	for(int i:pt){
		if(i*i>x)break;
		if(x%i==0)fc.insert(i);
		while(x%i==0)x/=i;
	}
	if(x>1)fc.insert(x);
}
loli calc(loli x){
	loli res=0;
	for(int i=1;i<=n;i++)res+=a[i]<x?x-a[i]:std::min(a[i]%x,x-a[i]%x);
	return res;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=2;i<kM;i++){
		if(!pr[i])pt+=i;
		for(int j:pt){
			if(i*j>=kM)break;
			pr[i*j]=true;
			if(i%j==0)break;
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	std::shuffle(a+1,a+1+n,std::mt19937(std::random_device{}()));
	for(int i=1;i<=std::min(50,n);i++)solve(a[i]-1),solve(a[i]),solve(a[i]+1);
	loli ans=n;
	for(loli i:fc)ans=std::min(ans,calc(i));
	cout<<ans;
	return 0;
}