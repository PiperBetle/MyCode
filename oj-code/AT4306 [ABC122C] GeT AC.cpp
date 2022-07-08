#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
std::string s;
int sum[100001],q,n;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>q>>s;s='~'+s;
	for(int i=2;i<=n;i++)sum[i]=sum[i-1]+(s[i-1]=='A'&&s[i]=='C');
	for(int l,r;q--;){
		cin>>l>>r;
		cout<<sum[r]-sum[l-1]-(s[l-1]=='A'&&s[l]=='C')<<'\n';
	}
	return 0;
}