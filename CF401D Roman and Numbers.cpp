#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#define int long long
using std::cin;using std::cout;
int m,f[1<<18|1][107][2],a[20],len;
bool vis[10];
std::string aa;
signed main(){
//	freopen("cramp.in","r",stdin);
//	freopen("cramp.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>aa>>m;f[0][0][0]=1;
	for(char c:aa)a[len++]=c-'0';
	for(int k=0;k<(1ll<<len);k++){
		std::fill_n(vis,10,false);
		for(int i=0;i<len;i++){
			if((k&(1ll<<i)||vis[a[i]]))continue;
			vis[a[i]]=true;
			for(int j=0;j<m;j++){
				if(a[i])f[k|(1ll<<i)][(j*10+a[i])%m][1]+=f[k][j][0];
				f[k|(1ll<<i)][(j*10+a[i])%m][1]+=f[k][j][1];
			}
		}
	}
	cout<<f[(1<<len)-1][0][1]<<'\n';
	return 0;
}