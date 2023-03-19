#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
std::pair<int,int>a[500007];
int f[500007][21],n,m;
std::stack<int>s;
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
#endif
inline int read(){
	int w=0,c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w;
}
signed main(){
//	freopen("stack.in","r",stdin);
//	freopen("stack.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i].first=read();
	for(int i=1;i<=n;i++)a[i].second=read(),f[i][0]=n+1;
	for(int i=0;i<=20;i++)f[n+1][i]=n+1;
	for(int i=1;i<=n;s.emplace(i++))
		while(!s.empty()&&(a[s.top()].first==a[i].first||a[s.top()].second<=a[i].second))
			f[s.top()][0]=i,s.pop();
	for(int i=1;i<=20;i++)for(int j=1;j<=n;j++)f[j][i]=f[f[j][i-1]][i-1];
	while(m--){
		int l=read(),r=read(),ans=1;
		for(int i=20;i>=0;i--)if(f[l][i]<=r)l=f[l][i],ans+=(1<<i);
		printf("%d\n",ans);
	}
	return 0;
}