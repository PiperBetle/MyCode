#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int a[200007],up[200007],dw[200007],tree[200007],n;
inline int lowbit(int x){return x&(-x);}
inline void add(int x,int k=1){for(;x<=n;x+=lowbit(x))tree[x]+=k;}
inline int find(int x,int sum=0){for(;x;x-=lowbit(x))sum+=tree[x];return sum;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,ans1=0,ans2=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		up[i]=find(n)-find(a[i]);
		dw[i]=find(a[i]-1);
		add(a[i]);
	}
	memset(tree,0,sizeof tree);
	for(i=n;i>=1;i--){
		ans1+=up[i]*(find(n)-find(a[i]));
		ans2+=dw[i]*find(a[i]-1);
		add(a[i]);
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}