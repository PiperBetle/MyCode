#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
struct car{int cnt,data;car(){cnt=data=0x3f3f3f3f;}}f[2000007];
int a[20];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,k,n,m;
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>a[i];
	f[0].cnt=f[0].data=0;
	for(k=0;k<(1<<n);k++)for(i=0;i<n;i++){
		if(k&(1<<i))continue;
		int now=k|(1<<i);
		car t=f[k];
		if(t.data+a[i]>m)t.cnt++,t.data=std::min(t.data,a[i]);
		else if(t.data+a[i]==m)t.cnt++,t.data=0;
		else t.data+=a[i];
		if((t.cnt<f[now].cnt)||(t.cnt==f[now].cnt&&t.data<f[now].data))f[now]=t;
	}
	if(f[(1<<n)-1].data!=0)f[(1<<n)-1].cnt++;
	cout<<f[(1<<n)-1].cnt;
	return 0;
}