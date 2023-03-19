#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
struct edge{int u,v,t;bool operator<(const edge&n)const{return t<n.t;}}a[6007];
int f[6007],size[6007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,T,ans=0;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++)f[i]=i,size[i]=1;
		for(i=1;i<n;i++)cin>>a[i].u>>a[i].v>>a[i].t;
		std::sort(a+1,a+n);
		for(i=1,ans=0;i<n;i++){
			int fx=find(a[i].u),fy=find(a[i].v);
			if(fx!=fy){
				ans+=(size[fx]*size[fy]-1)*(a[i].t+1);
				f[fx]=fy;
				size[fy]+=size[fx];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}