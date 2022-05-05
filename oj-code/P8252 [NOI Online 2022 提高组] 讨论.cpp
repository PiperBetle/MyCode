#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
std::vector<int>a[200007];
int id[200007],mx[200007];
bool vis[200007];
using std::cin;using std::cout;
inline int read(){
	int w=0,c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w;
}
signed main(){
	freopen("discuss.in","r",stdin);
	freopen("discuss.out","w",stdout);
	int T;cin>>T;while(T--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			int cnt=read();
			a[i].resize(cnt);
			for(int j=0;j<cnt;j++)a[i][j]=read();
			id[i]=i;vis[i]=false;mx[i]=0;
		}
		std::sort(id+1,id+1+n,[](const int &x,const int &y){return a[x].size()<a[y].size();});
		for(int _i=1;_i<=n;_i++){
			int i=id[_i];
			for(int j:a[i])vis[j]=true;
			for(int j:a[i]){
				if(!vis[j]||!mx[j])continue;
				for(auto k:a[mx[j]])
					if(vis[k])vis[k]=false;
					else{printf("YES\n%d %d\n",mx[j],i);goto next_data;}
			}
			for(int j:a[i])vis[j]=false,mx[j]=i;
		}
		puts("NO");next_data:;
	}
	return 0;
}