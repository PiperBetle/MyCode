#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using std::cin;using std::cout;
std::string a,b;
int f[2007][2007],u[2007][26],v[2007][26];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		int n;cin>>n>>a>>b;a=" "+a,b=" "+b;
		std::fill(u[1],u[n+1],0);std::fill(v[1],v[n+1],0);
		for(int i=1;i<=n;i++)u[i][a[i]-'a']++,v[i][b[i]-'a']++;
		for(int i=1;i<=n;i++)for(int j=0;j<26;j++)u[i][j]+=u[i-1][j],v[i][j]+=v[i-1][j];
		for(int i=0;i<26;i++)if(u[n][i]!=v[n][i])goto impossible;
		for(int i=1;i<=n;i++)std::fill_n(f[i],n+1,0x3f3f3f3f);
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
			f[i][j]=f[i-1][j]+1;
			if(a[i]==b[j])f[i][j]=std::min(f[i-1][j-1],f[i][j]);
			if(u[i][b[j]-'a']<v[j][b[j]-'a'])f[i][j]=std::min(f[i][j],f[i][j-1]);
		}
		cout<<f[n][n]<<'\n';continue;
		impossible:cout<<"-1\n";
	}
	return 0;
}