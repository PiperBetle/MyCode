#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf;
int sta[50];
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
	#define putchar(x) (p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x)))
#endif
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
inline void write(int x){
	if(x==0){putchar('0');return;}
	int len=0;
	if(x<0)x=-x,putchar('-');
	while(x)sta[len++]=x%10+'0',x/=10;
	while(len--)putchar(sta[len]);
}
int a[100007],pr[100007],pt[100007],n,len,next[100007],st[25][100007];
bool cnt[100007];
std::vector<int>s[100007];
bool check(int x){
	for(auto it:s[x])if(cnt[it])return false;
	for(auto it:s[x])cnt[it]=true;
	return true;
}
int query(int l,int r,int cnt=1){
	for(int i=20;i>=0;i--)if(st[i][l]<=r)
		l=st[i][l],cnt+=(1<<i);
	return cnt;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,m,l,r;
	n=read(),m=read();
	for(i=1;i<=n;i++)a[i]=read();
	for(pr[1]=true,i=2;i<=100000;i++){
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=100000;j++){
			pr[i*pt[j]]=true;
			if(i%pt[j]==0)break;
		}
	}
	for(i=1;i<=len;i++)for(j=pt[i];j<=100000;j+=pt[i])s[j].emplace_back(i);
	for(i=1,j=0;i<=n;i++){
		for(auto it:s[a[i-1]])cnt[it]=false;
		while(j<n&&check(a[j+1]))j++;
		st[0][i]=next[i]=j+1;
	}
	for(i=0;i<=20;i++)st[i][n+1]=n+1;
	for(i=1;i<=20;i++)for(j=1;j<=n;j++)st[i][j]=st[i-1][st[i-1][j]];
	while(m--)l=read(),r=read(),write(query(l,r)),putchar('\n');
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}