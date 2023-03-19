#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
class fastIO{private:char ibuf[50007],*p1=ibuf,*p2=ibuf,obuf[50007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,50007,stdin),p1==p2)?(file_end=true),char(EOF):*p1++;}void put(const char x){p3-obuf<50007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();!isgraph(t);t=get());return*this;}template<typename any>typename std::enable_if<std::is_same<any,char>::value,any>::type tpval(){char t;for(t=get();!isgraph(t);t=get());return t;}fastIO&operator>>(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return*this;}template<typename any>typename std::enable_if<std::is_same<any,std::string>::value,any>::type tpval(){std::string t;char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return t;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,any>::type tpval(){any t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return t;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,any>::type tpval(){any t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return t;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}template<typename any1,typename any2>std::pair<any1,any2>tpval(){return std::pair<any1,any2>(tpval<any1>(),tpval<any2>());}template<typename any>fastIO&read(any&t){return*this>>t;}fastIO&read(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}template<typename any,typename...args>fastIO&read(any&t1,args&...t2){return(*this>>t1).read(t2...);}fastIO&operator<<(const char t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=char(t%10+48),t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=char(t%10+48),t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}template<typename any>fastIO&write(const any&t){return*this<<t;}template<typename any,typename...args>fastIO&write(const any&t1,const args&...t2){return(*this<<t1).write(t2...);}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=3e5+1,kL=std::__lg(kN)+1;
std::vector<pii>ed[kN];
int n,m,l,fa[kN],dep[kN],dis[kN],p[kN][kL],mx,cnt[kN],sum,res,ans;
inline void dfs1(int u){
	for(auto[v,t]:ed[u]){
		if(v==fa[u])continue;
		fa[v]=p[v][0]=u;dep[v]=dep[u]+1;dis[v]=dis[u]+t;dfs1(v);
	}
}
inline int LCA(int a,int b){
	if(dep[a]>dep[b])std::swap(a,b);
	for(int i=l;i>=0;i--)if(dep[a]+(1<<i)<=dep[b])b=p[b][i];
	if(a==b)return a;
	for(int i=l;i>=0;i--)if(p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return fa[a];
}
struct node{int x,y,z,val;}q[kN];
inline void dfs2(int u){
	for(auto[v,t]:ed[u]){
		if(v==fa[u])continue;
		dfs2(v);cnt[u]+=cnt[v];
		if(cnt[v]==sum)res=std::max(res,t);
	}
}
inline bool check(int x){
	memset(cnt+1,0,sizeof(*cnt)*n);
	sum=0,res=0;
	for(int i=1;i<=m;i++)if(q[i].val>x)cnt[q[i].x]++,cnt[q[i].y]++,cnt[q[i].z]-=2,sum++;
	dfs2(1);return mx-res<=x;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int lt=0,rt=0,mid;
	fio>>n>>m;l=std::__lg(n);
	for(int i=1,u,v,t;i<n;i++)fio>>u>>v>>t,ed[u].emplace_back(v,t),ed[v].emplace_back(u,t);
	dep[1]=1;dfs1(1);
	for(int j=1;j<=l;j++)for(int i=1;i<=n;i++)p[i][j]=p[p[i][j-1]][j-1];
	for(int i=1;i<=m;i++)fio>>q[i].x>>q[i].y,mx=std::max(mx,q[i].val=dis[q[i].x]+dis[q[i].y]-2*dis[q[i].z=LCA(q[i].x,q[i].y)]);
	rt=mx;while(lt<=rt)if(check(mid=(lt+rt)>>1))ans=mid,rt=mid-1;else lt=mid+1;
	fio<<ans;
	return 0;
}