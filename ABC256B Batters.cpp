#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
int n,a[4],b[4];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=0;j<4;j++)b[j]=a[j],a[j]=0;
		b[0]++;
		for(int j=0;j<4;j++)if(j+x<4)a[j+x]+=b[j];
	}
	cout<<n-(a[0]+a[1]+a[2]+a[3]);
	return 0;
}