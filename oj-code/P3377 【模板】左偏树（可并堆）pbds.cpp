#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ext/pb_ds/priority_queue.hpp>
using std::cin;using std::cout;
int f[100007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
__gnu_pbds::priority_queue<int>q[100007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	int n,m,t,x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	while(m--){
		cin>>t;
		if(t==1){
			cin>>x>>y;
			if(!f[x]||!f[y])continue;
			int fx=find(x),fy=find(y);
			if(fx!=fy)f[fx]=fy,q[fy].join(q[fx]);
		}else{
			cin>>x;
			int fx=find(f[x]);
			if(!f[x])cout<<"-1\n"
			else cout<<
		}
	}
	return 0;
}