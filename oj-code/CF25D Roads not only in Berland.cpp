#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
int f[1007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
std::vector<std::pair<int,int>>s1,s2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,u,v;
	cin>>n;
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<n;i++){
		cin>>u>>v;
		int fx=find(u),fy=find(v);
		if(fx!=fy)f[fy]=fx;
		else s1.emplace_back(u,v);
	}
	for(i=2;i<=n;i++){
		int f1=find(1),f2=find(i);
		if(f1!=f2)f[f2]=f1,s2.emplace_back(1,i);
	}
	cout<<s1.size()<<'\n';
	for(i=s1.size()-1;i>=0;i--)
		cout<<s1[i].first<<' '<<s1[i].second<<' '<<s2[i].first<<' '<<s2[i].second<<'\n';
	return 0;
}