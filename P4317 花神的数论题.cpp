#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using std::cin;using std::cout;
int f[60][60][60][2],sta[60];
constexpr int MOD=10000007;
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=t*a%MOD;return t;}
int dfs(int pos,int num,int cnt,bool lim){
	if(!pos)return num==cnt;
	if(~f[pos][num][cnt][lim])return f[pos][num][cnt][lim];
	int ans=0,up=lim?sta[pos]:1;
	for(int i=0;i<=up;i++)ans+=dfs(pos-1,num,cnt+i,lim&&(i==sta[pos]));
	return f[pos][num][cnt][lim]=ans;
}
int solve(int x){
	int len=0,ans=1;
	while(x)sta[++len]=x&1,x>>=1;
	for(int i=1;i<=len;i++)memset(f,-1,sizeof f),(ans*=qp(i,dfs(len,i,0,1)))%=MOD;
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	int n;cin>>n;cout<<solve(n);
	return 0;
}