#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using std::cin;using std::cout;
constexpr auto MOD=998244353;
int pw[20],sta[20],k;
int solve(int x){
	int len=0;
	memset(f,-1,sizeof -1);
	while(x)sta[++len]=x%10,x/=10;
	// return
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	for(int i=pw[i]=1;i<=18;i++)pw[i]=pw[i-1]*10%MOD;
	int r,l;cin>>k>>l>>r;
	cout<<(solve(r)-solve(l-1)+MOD)%MOD;
	return 0;
}