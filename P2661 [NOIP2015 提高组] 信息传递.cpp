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
int n,ans=0x3f3f3f3f,fat[kN],dis[kN];
int find(int x){
	if(fat[x]==x)return x;
	int fa=fat[x];
	fat[x]=find(fat[x]);
	dis[x]+=dis[fa];
	return fat[x];
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)ans=std::min(ans,dis[y]+1);
	else fat[fx]=fy,dis[x]=dis[y]+1;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)fat[i]=i;
	for(int i=1,x;i<=n;i++)cin>>x,merge(i,x);
	cout<<ans;
	return 0;
}