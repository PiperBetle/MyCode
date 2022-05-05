#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
using std::cin;using std::cout;
std::unordered_map<int,int>f,d;
inline int find(int x){
	if(!f.count(x))f[x]=x;
	if(f[x]==x)return x;
	int fx=find(f[x]);
	d[x]^=d[f[x]];
	return f[x]=fx;
}
std::string data;
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,x,y,flag;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>x>>y>>data;
		flag=(data!="even");
		int fx=find(--x),fy=find(y);
		if(fx!=fy)f[fy]=fx,d[fy]=flag^d[x]^d[y];
		else if(flag!=(d[x]^d[y]))return cout<<i-1,0;
	}
	cout<<m;
	return 0;
}