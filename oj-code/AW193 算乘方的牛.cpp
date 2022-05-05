#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int n,dep;
inline unsigned gcd(unsigned a,unsigned b){
	if(!a)return b;
	if(!b)return a;
	unsigned t=__builtin_ctz(a|b);
	a>>=__builtin_ctz(a);
	do{
		b>>=__builtin_ctz(b);
		if(a>b)std::swap(a,b);
		b-=a;
	}while(b);
	return a<<t;
}
bool dfs(int now,int a,int b){
	if(now>dep)return false;
	if(a==n||b==n)return true;
	if(a<b)std::swap(a,b);
	if((a<<(dep-now))<n)return false;
	if(a&&b&&n%gcd(a,b))return false;
	if(dfs(now+1,a,a<<1))return true;
    if(dfs(now+1,a<<1,b))return true;
    if(dfs(now+1,a,a+b))return true;
    if(dfs(now+1,a+b,b))return true;
    if(dfs(now+1,b<<1,b))return true;
    if(dfs(now+1,a,b<<1))return true;
    if(dfs(now+1,a,a-b))return true;
    if(dfs(now+1,a-b,b))return true;
	return false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	for(dep=0;;dep++)if(dfs(0,1,0))return cout<<dep,0;
}