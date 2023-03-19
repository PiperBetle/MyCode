#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int lowbit(int x){return x&-x;}
int n,t1[100007],t2[100007];
inline void add(int c[],int x,int k){for(;x<=n;x+=lowbit(x))c[x]+=k;}
inline int query(int c[],int x,int sum=0){for(;x;x-=lowbit(x))sum+=c[x];return sum;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,t,pre=0,m,l,r;
	char c;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>t,add(t1,i,t-pre),add(t2,i,(t-pre)*(i-1)),pre=t;
	while(m--){
		cin>>c>>l>>r;
		if(c=='Q')cout<<query(t1,r)*r-query(t2,r)-query(t1,l-1)*(l-1)+query(t2,l-1)<<'\n';
		else cin>>t,add(t1,l,t),add(t1,r+1,-t),add(t2,l,t*(l-1)),add(t2,r+1,t*-r);
	}
	return 0;
}