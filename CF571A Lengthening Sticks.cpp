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
int a,b,c,l;
loli ans=1;
void del(int x,int y,int z){
	for(int i=std::max(x+y-z,0);i<=l;i++){
		int t=std::min(z+i-x-y,l-i);
		ans-=1ll*(t+1)*(t+2)/2;
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>a>>b>>c>>l;
	for(int i=1;i<=l;i++)ans+=1ll*(i+1)*(i+2)/2;
	del(a,b,c);del(a,c,b);del(b,c,a);
	cout<<ans;
	return 0;
}