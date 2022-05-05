#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
struct mt{int s,c;int max()const{return std::max(s,c);}}a[500007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].s>>a[i].c;
	std::sort(a+1,a+1+n,[](const mt &x,const mt &y){
		return x.max()==y.max()?x.s<y.s:x.max()<y.max();
	});
	for(int i=1;i<=n;i++)if(a[i].s>=m)m=std::max(m,a[i].c),ans++;
	cout<<ans;
	return 0;
}