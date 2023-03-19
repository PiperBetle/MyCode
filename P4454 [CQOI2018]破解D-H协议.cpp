#include<iostream>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#define int long long
using std::cin;using std::cout;
inline int qp(int a,int b,int p,int t=1){for(;b;b>>=1,a=a*a%p)if(b&1)t=t*a%p;return t;}
std::unordered_map<int,int>mp;
int bsgs(int a,int b,int p){
	mp.clear();
	int size=ceil(sqrt(p)),mul=b;
	for(int i=1;i<=size;i++)mp[mul=mul*a%p]=i;
	int step=qp(a,size,p);mul=1;
	for(int i=1;i<=size;i++)if(mp.count(mul=mul*step%p))return i*size-mp[mul];
	return -1;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int g,p,n,A,B;cin>>g>>p>>n;
	while(n--)cin>>A>>B,cout<<qp(B,bsgs(g,A,p),p)<<'\n';
	return 0;
}