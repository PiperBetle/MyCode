#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=201;
int n,a[N][N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,x=1,y=n/2+1;i<=n*n;i++){
		a[x--][y++]=i;
		if(x==0)x=n;
		if(y==n+1)y=1;
		if(a[x][y]){
			if((x+=2)>n)x-=n;
			if(!--y)y=n;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)		
		a[i][j+n]=a[i][n-j+1],
		a[i+n][j]=a[n-i+1][j],
		a[i+n][j+n]=a[n-i+1][n-j+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<'R'<<a[i][j]<<' ';
		for(int j=n+1;j<=n*2;j++)cout<<'G'<<a[i][j]<<' ';
		cout<<'\n';
	}
	for(int i=n+1;i<=n*2;i++){
		for(int j=1;j<=n;j++)cout<<'Y'<<a[i][j]<<' ';
		for(int j=n+1;j<=n*2;j++)cout<<'B'<<a[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}