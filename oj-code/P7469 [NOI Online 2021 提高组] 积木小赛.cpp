#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using std::cin;using std::cout;
const int kN=3001,MOD=1e9+7;
std::string a,b;
int n,m;
long long h[kN*kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n;
	a.reserve(n+1);b.reserve(n+1);
	cin>>a>>b;a='~'+a;b='~'+b;
	for(int i=1;i<=n;i++){
		long long v=0;
		for(int j=i,k=1;j<=n;j++){
			while(k<=n&&a[k]!=b[j])k++;
			if(k++>n)break;
			h[++m]=(v=v*MOD+b[j]);
		}
	}
	std::sort(h+1,h+1+m);
	cout<<std::unique(h+1,h+1+m)-h-1;
	return 0;
}