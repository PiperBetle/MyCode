#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>
#include<vector>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
constexpr int kN=1e4+7,kM=5e4+7,kL=std::__lg(kN)+1,inf=0x3f3f3f3f;
struct edge1{int u,v,t;friend bool operator<(const edge1 &x,const edge1 &y){return x.t>y.t;}}s1[kM];
struct edge2{int v,t;};
int n,m,l,q,f[kN],dep[kN],p[kN][kL],w[kN][kL];
bool vis[kN];
std::vector<edge2>s2[kN];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int u){
	vis[u]=true;
	for(auto[v,t]:s2[u])if(!vis[v])dep[v]=dep[u]+1,p[v][0]=u,w[v][0]=t,dfs(v);
}
int LCA(int a,int b,int ans=inf){
	if(find(a)!=find(b))return -1;
	if(dep[a]>dep[b])std::swap(a,b);
	for(int i=l;i>=0;i--)if(dep[a]+(1<<i)<=dep[b])ans=std::min(ans,w[b][i]),b=p[b][i];
	if(a==b)return ans;
	for(int i=l;i>=0;i--)if(p[a][i]!=p[b][i])ans=std::min({ans,w[a][i],w[b][i]}),a=p[a][i],b=p[b][i];
	return std::min({ans,w[a][0],w[b][0]});
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n>>m;l=std::__lg(n);
	for(int i=1;i<=m;i++)fio>>s1[i].u>>s1[i].v>>s1[i].t;
	std::iota(f+1,f+1+n,1);std::sort(s1+1,s1+1+m);
	for(int i=1,fx,fy;i<=m;i++){
		fx=find(s1[i].u),fy=find(s1[i].v);
		if(fx==fy)continue;else f[fx]=fy;
		s2[fx].emplace_back(fy,s1[i].t);
		s2[fy].emplace_back(fx,s1[i].t);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i),p[i][0]=i,w[i][0]=inf;
	for(int j=1;j<=l;j++)for(int i=1;i<=n;i++)
		p[i][j]=p[p[i][j-1]][j-1],w[i][j]=std::min(w[i][j-1],w[p[i][j-1]][j-1]);
	int q,x,y;fio>>q;while(q--)fio>>x>>y<<LCA(x,y)<<'\n';
	return fio.flush();
}