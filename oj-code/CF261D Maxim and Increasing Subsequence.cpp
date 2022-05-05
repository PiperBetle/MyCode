#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using std::cin;using std::cout;
int a[200007],f[200007],b[200007],tree[200007],n,s;
inline int lowbit(int x){return x&-x;}
inline void change(int x,int k){for(;x<=s;x+=lowbit(x))tree[x]=std::max(tree[x],k);}
inline int query(int x,int k=0){for(;x;x-=lowbit(x))k=std::max(tree[x],k);return k;}
signed main(){
//	freopen("twocicircle.in","r",stdin);
//	freopen("twocicircle.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,T,n,m,sum,ans;
	cin>>T>>n>>s>>m;
	while(T--){
		memset(f,0,sizeof f);
		memset(b,0,sizeof b);
		memset(tree,0,sizeof tree);
		sum=ans=0;
		for(i=1;i<=n;i++)cin>>a[i],sum+=!b[a[i]],b[a[i]]=1;
		if(sum<=m){cout<<sum<<'\n';continue;}
		for(i=1;i<=m;i++)for(j=1;j<=n;j++){
			int x=query(a[j]-1)+1;
			if(x>f[j])f[j]=x,change(a[j],x),ans=std::max(ans,x);	
		}
		cout<<ans<<'\n';
	}
	return 0;
}