#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int sta[20],f[20]
int solve(int x,int dig){
	int len=0;
	while(x)sta[++len]=x%10,x/=10;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	int n,ans=0;cin>>n;
	for(int i=1;i<=9;i++)ans+=i*solve(n,i);
	return 0;
}