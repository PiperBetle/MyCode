#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<ranges>
using std::cin;using std::cout;
std::string s;
int f[2][4][4][4][4];
inline void be_max(auto &x,auto y){if(x<y)x=y;}
inline int calc(int x,int y,int z){
	if(!x&&!y)return 1;
	if(!x)return (y!=z)+1;
	if(x!=y&&y!=z&&x!=z)return 3;
	if(x==y&&y==z&&x==z)return 1;
	return 2;
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	int n,i=0,ans=0;cin>>n>>s;
	memset(f,-1,sizeof f);f[0][0][0][0][0]=0;
	for(int fd:s|std::views::transform([](char c){if(c=='M')return 1;if(c=='F')return 2;if(c=='B')return 3;return EOF;})){
		i=!i;
		for(int a1=0;a1<4;a1++)for(int a2=0;a2<4;a2++)for(int b1=0;b1<4;b1++)for(int b2=0;b2<4;b2++)if(~f[!i][a1][a2][b1][b2])
			be_max(f[i][a2][fd][b1][b2],f[!i][a1][a2][b1][b2]+calc(a1,a2,fd)),be_max(f[i][a1][a2][b2][fd],f[!i][a1][a2][b1][b2]+calc(b1,b2,fd));
	}
	for(int a1=0;a1<4;a1++)for(int a2=0;a2<4;a2++)for(int b1=0;b1<4;b1++)for(int b2=0;b2<4;b2++)be_max(ans,f[i][a1][a2][b1][b2]);
	cout<<ans;
	return 0;
}