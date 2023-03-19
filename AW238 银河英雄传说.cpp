#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int f[300007],size[300007],b[300007];
inline int find(int x){
	if(f[x]==x)return x;
	int fx=find(f[x]);
	size[x]+=size[f[x]];
	return f[x]=fx;
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,T,x,y;
	char c;
	for(i=0;i<300007;i++)f[i]=i,b[i]=1;
	cin>>T;
	while(T--){
		cin>>c>>x>>y;
		if(c=='M'){
			int fx=find(x),fy=find(y);
			f[fx]=fy;
			size[fx]+=b[fy];
			b[fy]+=b[fx];
		}
		else{
			int fx=find(x),fy=find(y);
			if(fx!=fy)cout<<"-1\n";
			else cout<<std::max(0,abs(size[x]-size[y])-1)<<'\n';
		}
	}
	return 0;
}