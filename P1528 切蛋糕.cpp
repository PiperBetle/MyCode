#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int a[57],t[57],b[1107],n,m,mid,sum[1107],tot,used;
bool check(int last,int now){
	if(now<=0)return true;
	if(tot-used<sum[mid])return false;
	for(;last<=n;last++){
		if(t[last]<b[now])continue;
		t[last]-=b[now];
		if(t[last]<b[1])used+=t[last];
		if(b[now-1]==b[now]){if(check(last,now-1))return true;}
		else if(check(1,now-1))return true;
		if(t[last]<b[1])used-=t[last];
		t[last]+=b[now];
	}
	return 0;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],tot+=a[i];
	std::sort(a+1,a+1+n);
	cin>>m;
	for(i=1;i<=m;i++)cin>>b[i];
	std::sort(b+1,b+1+m);
	for(i=1;i<=m;i++)sum[i]=sum[i-1]+b[i];
	while(tot<sum[m])m--;
	int l=0,r=m;
	while(l<=r){
		for(used=0,i=1;i<=n;i++)t[i]=a[i];
		if(check(1,mid=(l+r)>>1))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}