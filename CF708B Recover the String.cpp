#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
int A,B,C,D;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>A>>B>>C>>D;
	int n0=int(sqrt(A*2+.25)+.5);
	int n1=int(sqrt(D*2+.25)+.5);
	if(!B&&!C)n0<n1?n0--:n1--;
	if(n0*(n0-1)!=2*A||n1*(n1-1)!=2*D||n0*n1!=B+C)return cout<<"Impossible",0;
	for(int i=n0+n1;i;i--)
		if(B>=n1)cout<<0,B-=n1;
		else cout<<1,n1--;
	return 0;
}近乎