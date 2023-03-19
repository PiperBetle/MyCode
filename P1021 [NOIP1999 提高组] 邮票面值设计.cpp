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
constexpr int kN=500,inf=0x3f3f3f3f;
int n,k,ans=-inf,f[kN];
std::basic_string<int>a={1},b;
void dfs(int now){
	memset(f,0x3f,sizeof(int)*kN);
	f[0]=0;int cnt=1;
	for(;;cnt++){
		for(int i:a)if(i>cnt)break;else
			f[cnt]=std::min(f[cnt],f[cnt-i]+1);
		if(f[cnt]>n)break;
	}
	if(--cnt>ans)ans=cnt,b=a;
	if(now==k)return;
	for(int i=a.back()+1;i<=cnt+1;i++)
		a+=i,dfs(now+1),a.pop_back();
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	dfs(1);
	for(int i:b)cout<<i<<' ';
	cout<<"\nMAX="<<ans;
	return 0;
}