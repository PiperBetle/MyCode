#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int ans=0x3f3f3f3f3f3f3f3f;
inline void dfs2(int a,int b,int p3){
	if(p3=='+')ans=std::min(ans,a+b);
	if(p3=='*')ans=std::min(ans,a*b);
}
void dfs3(int a,int b,int c,int p2,int p3){
	if(p2=='+'){
		dfs2(a,b+c,p3);
		dfs2(b,a+c,p3);
		dfs2(c,a+b,p3);
	}else{
		dfs2(a,b*c,p3);
		dfs2(b,a*c,p3);
		dfs2(c,a*b,p3);
	}
}
void dfs4(int a,int b,int c,int d,int p1,int p2,int p3){
	if(p1=='+'){
		dfs3(a,b,c+d,p2,p3);
		dfs3(a,c,b+d,p2,p3);
		dfs3(a,d,b+c,p2,p3);
		dfs3(b,c,a+d,p2,p3);
		dfs3(b,d,a+c,p2,p3);
		dfs3(c,d,a+b,p2,p3);
	}else{
		dfs3(c,d,a*b,p2,p3);
		dfs3(a,b,c*d,p2,p3);
		dfs3(a,c,b*d,p2,p3);
		dfs3(a,d,b*c,p2,p3);
		dfs3(b,c,a*d,p2,p3);
		dfs3(b,d,a*c,p2,p3);
	}
}
signed main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int a,b,c,d;
	char p1,p2,p3;
	cin>>a>>b>>c>>d>>p1>>p2>>p3;
	if(p1=='+'&&p2=='+'&&p3=='+')return cout<<a+b+c+d<<'\n',0;
	if(p1=='*'&&p2=='*'&&p3=='*')return cout<<a*b*c*d<<'\n',0;
	dfs4(a,b,c,d,p1,p2,p3);
	cout<<ans;
	return 0;
}