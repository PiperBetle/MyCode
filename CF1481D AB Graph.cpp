#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<array>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1001;
char a[kN][kN];
int n,m;
inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	if(m%2){
		cout<<"YES\n";
		for(int k=1;k<=m+1;k++)cout<<2-k%2<<' ';
		cout<<'\n';
		return;
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		int _ab=0,_ba=0;
		if(a[i][j]==a[j][i]){
			cout<<"YES\n";
			for(int k=1;k<=m+1;k++)cout<<(k%2?i:j)<<' ';
			cout<<'\n';
			return;
		}
		if(a[i][j]=='a'&&a[j][i]=='b')_ab=j;
		if(a[i][j]=='b'&&a[j][i]=='a')_ba=j;
		if(m%4==0&&_ab&&_ba){
			cout<<"YES\n"<<i<<' '; 
			for(int k=1;k<=m/4;k++)cout<<_ab<<' '<<i<<' ';
			for(int k=1;k<=m/4;k++)cout<<_ba<<' '<<i<<' ';
			cout<<'\n';
			return;
		}
		if(m%4==2&&_ab&&_ba){
			cout<<"YES\n"<<i<<' ';
			for(int k=1;k<=m/2;k++)cout<<(k%2?i:_ab)<<' ';
			for(int k=1;k<=m/2;k++)cout<<(k%2?i:_ba)<<' ';
			cout<<'\n';
			return;
		}
	}
	cout<<"NO\n";
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--)solve();
	return 0;
}