#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using std::cin;using std::cout;
int st[500007][20];
std::map<int,int>mp;
inline int query(int l,int r){
	int t=std::__lg(r-l+1);
	return std::max(st[l][t],st[r-(1<<t)+1][t]);
}
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,q;cin>>n;
	for(int i=1,t;i<=n;i++)cin>>t>>st[i][0],mp[t]=i;
	for(int j=1;(1<<j)<=n;j++)for(int i=1;i+(1<<j)-1<=n;i++)
		st[i][j]=std::max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	cin>>q;while(q--){
		int x,y;cin>>y>>x;
		if(y>=x){cout<<"flase\n";continue;}
		bool fx=mp.count(x),fy=mp.count(y),flag=0;
		if(!fx&&!fy){cout<<"maybe\n";continue;}
		auto ix=mp.lower_bound(x),iy=mp.lower_bound(y);
		if(iy==mp.end()){cout<<"maybe\n";continue;}
		int idx=ix==mp.end()?mp.size()+1:ix->second,idy=iy->second-!fy;
		int num=idy+1<=idx-1?query(idy+1,idx-1):0;
		if(fx){flag=st[idx][0]>num;}if(fy){flag=st[idy][0]>num;}
		if(fx&&fy)flag=st[idy][0]>=st[idx][0]&&st[idx][0]>num;
		if(fy&&fx&&idy-idx==y-x)cout<<(flag?"true\n":"false\n");
		else cout<<(flag?"maybe\n":"false\n");
	}
	return 0;
}