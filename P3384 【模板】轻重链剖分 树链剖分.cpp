#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
#define int long long
constexpr int kN=1e5+7;
int n,m,cnt,rt,MOD,a[kN],w[kN],size[kN],dep[kN],fa[kN],gs[kN],top[kN],dfn[kN],rnk[kN];
std::vector<int>ed[kN];
void dfs1(int u){
	for(int v:ed[u]){
		if(v==fa[u])continue;
		fa[v]=u;size[v]=1;dep[v]=dep[u]+1;
		dfs1(v);size[u]+=size[v];
		if(size[v]>size[gs[u]])gs[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;dfn[u]=++cnt;a[cnt]=w[u];rnk[cnt]=u;
	if(!gs[u])return;else dfs2(gs[u],t);
	for(int v:ed[u])if(v!=fa[u]&&v!=gs[u])dfs2(v,v);
}
struct stn{int li,ri,sum,add;}s[kN<<2];
inline stn operator+(const stn &x,const stn &y){return stn{x.li,y.ri,(x.sum+y.sum)%MOD,0};}
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((s[now].li+s[now].ri)>>1)
void build(int now,int l,int r){
	s[now].li=l;s[now].ri=r;if(l==r){s[now].sum=a[l];return;}
	build(ls,l,mid);build(rs,mid+1,r);s[now]=s[ls]+s[rs];
}
inline void spread(int now){
	s[ls].sum=(s[ls].sum+s[now].add*(s[ls].ri-s[ls].li+1))%MOD;
	s[rs].sum=(s[rs].sum+s[now].add*(s[rs].ri-s[rs].li+1))%MOD;
	(s[ls].add+=s[now].add)%=MOD;(s[rs].add+=s[now].add)%=MOD;s[now].add=0;
}
void add_interval(int now,int x,int y,int k){
	if(x<=s[now].li&&s[now].ri<=y){s[now].add+=k;s[now].sum+=k*(s[now].ri-s[now].li+1);return;}
	if(s[now].add){spread(now);}if(x<=mid){add_interval(ls,x,y,k);}if(y>mid){add_interval(rs,x,y,k);}s[now]=s[ls]+s[rs];
}
int sum_interval(int now,int x,int y){
	if(x<=s[now].li&&s[now].ri<=y){return s[now].sum;}int sum=0;
	if(s[now].add){spread(now);}if(x<=mid){sum+=sum_interval(ls,x,y);}if(y>mid){sum+=sum_interval(rs,x,y);}return sum%MOD;
}
void add_tree(int x,int y,int k){
	while(top[x]!=top[y]){if(dep[top[x]]<dep[top[y]])std::swap(x,y);add_interval(1,dfn[top[x]],dfn[x],k);x=fa[top[x]];}
	if(dep[x]>dep[y]){std::swap(x,y);}add_interval(1,dfn[x],dfn[y],k);
}
int sum_tree(int x,int y){
	int sum=0;while(top[x]!=top[y]){if(dep[top[x]]<dep[top[y]])std::swap(x,y);(sum+=sum_interval(1,dfn[top[x]],dfn[x]))%=MOD;x=fa[top[x]];}
	if(dep[x]>dep[y]){std::swap(x,y);}(sum+=sum_interval(1,dfn[x],dfn[y]))%=MOD;return sum;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n>>m>>rt>>MOD;
	for(int i=1;i<=n;i++)fio>>w[i];
	for(int i=1,u,v;i!=n;i++)fio>>u>>v,ed[u].emplace_back(v),ed[v].emplace_back(u);
	size[rt]=dep[rt]=1;dfs1(rt);dfs2(rt,rt);
	build(1,1,n);while(m--){
		int t,x,y;fio>>t>>x;
		switch(t){
		case 1:fio>>y>>t;add_tree(x,y,t%MOD);break;
		case 2:fio>>y<<sum_tree(x,y)<<'\n';break;
		case 3:fio>>t;add_interval(1,dfn[x],dfn[x]+size[x]-1,t);break;
		case 4:fio<<sum_interval(1,dfn[x],dfn[x]+size[x]-1)<<'\n';break;
		}
	}
	return fio.flush();
}