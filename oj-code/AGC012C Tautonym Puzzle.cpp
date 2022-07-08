#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
std::basic_string<int>a,b;
int m;
void dfs(long long n){
	if(!n)return;
	if(n&1)b+=m++,dfs(n/2);
	else a+=m++,dfs(n-1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	long long n;cin>>n;dfs(n);
	cout<<m+siz(a)+siz(b)<<'\n';
	for(int i=0;i<siz(a);i++)cout<<m-a[i]<<' ';
	for(int i=siz(b)-1;~i;i--)cout<<m-b[i]<<' ';
	for(int i=1;i<=siz(a)+siz(b);i++)cout<<i<<' ';
	return 0;
}