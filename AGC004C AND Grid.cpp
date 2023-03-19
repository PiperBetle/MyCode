#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
constexpr int kN=501;
char a[kN][kN],b[kN][kN],c[kN][kN];
int n,m;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		cin>>c[i][j];
		a[i][j]=b[i][j]='.';
		if(i==1||(j%2==0&&i!=n))a[i][j]='#';
		if(i==n||(j%2==1&&i!=1))b[i][j]='#';
		if(c[i][j]=='#')a[i][j]=b[i][j]='#';
	}
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=m;j++)cout<<a[i][j];
	cout<<'\n';
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=m;j++)cout<<b[i][j];
	return 0;
}