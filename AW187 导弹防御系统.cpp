#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int dep,n,a[57],up[57],dw[57];
bool dfs(int now,int l1,int l2){
	if(l1+l2>dep)return false;
	if(now==n+1)return true;
	int i,t;
	for(t=-1,i=1;i<=l1;i++)if(up[i]<a[now]){
		t=up[i];
		up[i]=a[now];
		if(dfs(now+1,l1,l2))return true;
		up[i]=t;
		break;
	}
	if(t==-1){
		up[l1+1]=a[now];
		if(dfs(now+1,l1+1,l2))return true;
	}
	for(t=-1,i=1;i<=l2;i++)if(dw[i]>a[now]){
		t=dw[i];
		dw[i]=a[now];
		if(dfs(now+1,l1,l2))return true;
		dw[i]=t;
		break;
	}
	if(t==-1){
		dw[l2+1]=a[now];
		if(dfs(now+1,l1,l2+1))return true;
	}
	return false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n,n){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(dep=0;;dep++)if(dfs(1,0,0))break;
		cout<<dep<<'\n';
	}
	return 0;
}