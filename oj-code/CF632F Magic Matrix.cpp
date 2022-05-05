#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
int a[2507][2507];
struct edge{int go,data;bool operator<(const edge &t){return data<t.data;}};
std::vector<edge>s[2507];
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
signed main(){
//	freopen("bdffbea.in","r",stdin);
//	freopen("bdffbea.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=read();
	for(int i=1;i<=n;i++)
		if(a[i][i])return printf("NOT MAGIC"),0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		if(a[i][j]!=a[j][i])return printf("NOT MAGIC"),0;
	if(n<=300){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)
			if(a[i][j]>std::max(a[i][k],a[k][j]))return printf("NOT MAGIC"),0;
		printf("MAGIC");
	}else{
		int F=sqrt(n>>8);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				if(i!=j)s[i].emplace_back(edge{j,a[i][j]});
		}
		for(int i=1;i<=n;i++)std::sort(s[i].begin(),s[i].end());
		for(int i=1;i<=n;i++){
			for(int j=0;j<F;j++)for(int k=0;k<F;k++){
				int go1=s[i][j].go,go2=s[go1][k].go;
				if(a[i][go2]>std::max(a[i][go1],a[go1][go2]))return printf("NOT MAGIC"),0;
			}// 枚举最小的最小
			for(int j=0;j<F;j++)for(int k=n-2;k>=n-F;k--){
				int go1=s[i][j].go,go2=s[go1][k].go;
				if(a[go1][go2]>std::max(a[i][go1],a[i][go2]))return printf("NOT MAGIC"),0;
			}// 枚举最小的最大
			for(int j=n-2;j>=n-F;j--)for(int k=0;k<F;k++){
				int go1=s[i][j].go,go2=s[go1][k].go;
				if(a[i][go1]>std::max(a[i][go2],a[go1][go2]))return printf("NOT MAGIC"),0;
			}// 枚举最大的最小
			// 为什么要最大的最大？
			// 保佑随机数据！！
			// 上香~~ ~~ ~~ ~~ ~~ ~~
		}
		printf("MAGIC");
	}
	return 0;
}