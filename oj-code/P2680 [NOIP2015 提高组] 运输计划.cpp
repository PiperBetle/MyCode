#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
constexpr int kN=3e5+7,kL=std::__lg(kN)+1;
struct edge{int v,t;};
std::vector<edge>ed[kN];
int n,m,l,fa[kN],dep[kN],dis[kN],p[kN][kL],mx,cnt[kN],sum,res,ans;
void dfs1(int u){
	for(auto[v,t]:ed[u]){
		if(v==fa[u])continue;
		fa[v]=p[v][0]=u;dep[v]=dep[u]+1;dis[v]=dis[u]+t;dfs1(v);
	}
}
int LCA(int a,int b){
	if(dep[a]>dep[b])std::swap(a,b);
	for(int i=l;i>=0;i--)if(dep[a]+(1<<i)<=dep[b])b=p[b][i];
	if(a==b)return a;
	for(int i=l;i>=0;i--)if(p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return fa[a];
}
struct node{int x,y,z,val;}q[kN];
void dfs2(int u){
	for(auto[v,t]:ed[u]){
		if(v==fa[u])continue;
		dfs2(v);cnt[u]+=cnt[v];
		if(cnt[v]==sum)res=std::max(res,t);
	}
}
bool check(int x){
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
	return fio.flush();
}