#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
constexpr int kN=100007,kM=std::__lg(kN)+1;
struct edge{int v,t;};
std::vector<edge>ed[kN];
int n,m,l,cnt,fa[kN],p[kN][kM],dfn[kN],rnk[kN],dep[kN];
bool vis[kN];
long long ans,dis[kN];
std::set<int>s;
void dfs(int u){
	dfn[u]=++cnt;rnk[cnt]=u;
	for(auto[v,t]:ed[u])if(v!=fa[u])p[v][0]=fa[v]=u,dep[v]=dep[u]+1,dis[v]=dis[u]+t,dfs(v);
}
int LCA(int a,int b){
	if(dep[a]>dep[b])std::swap(a,b);
	for(int i=l;i>=0;i--)if(dep[a]+(1<<i)<=dep[b])b=p[b][i];
	if(a==b)return a;
	for(int i=l;i>=0;i--)if(p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return fa[a];
}
inline long long calc(int x,int y){return dis[x]+dis[y]-2*dis[LCA(x,y)];}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n>>m;l=std::__lg(n);
	for(int i=1,u,v,t;i<n;i++)fio>>u>>v>>t,ed[u].emplace_back(v,t),ed[v].emplace_back(u,t);
	dep[1]=1;dfs(1);for(int j=1;j<=l;j++)for(int i=1;i<=n;i++)p[i][j]=p[p[i][j-1]][j-1];
	while(m--){
		int x,y,z;long long w;fio>>x;x=dfn[x];
		if(!vis[rnk[x]])s.insert(x);
		if(auto it=s.lower_bound(x);it==s.begin())y=*s.rbegin();else y=*--it;
		if(auto it=s.upper_bound(x);it==s.end())z=*s.begin();else z=*it;
		if(vis[rnk[x]])s.erase(x);
		x=rnk[x],y=rnk[y],z=rnk[z],w=calc(x,y)+calc(x,z)-calc(y,z);
		if(vis[x]){ans-=w;}else{ans+=w;}vis[x]=!vis[x];
		fio<<ans<<'\n';
	}
	return fio.flush();
}