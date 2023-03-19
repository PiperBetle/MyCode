#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?file_end=true:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(char c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(char c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
constexpr int kN=1e6+7;
constexpr long long inf=0x3f3f3f3f3f3f3f3f;
std::vector<int>ed[kN];
int n,fa[kN];
long long f[kN][2],ans,w[kN];
bool vis[kN];
inline void dfs(int u,int g){
	vis[u]=1;f[u][0]=0;f[u][1]=w[u];
	for(int v:ed[u])if(v!=g)dfs(v,g),f[u][0]+=std::max(f[v][0],f[v][1]),f[u][1]+=f[v][0];else f[v][1]=-inf;
}
inline void find(int u){
	while(!vis[u])vis[u]=true,u=fa[u];
	dfs(u,u);
	long long sum=std::max(f[u][0],f[u][1]);
	u=fa[u];dfs(u,u);
	ans+=std::max(sum,std::max(f[u][0],f[u][1]));
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n;
	for(int i=1,t;i<=n;i++)fio>>w[i]>>t,ed[t].emplace_back(i),fa[i]=t;
	for(int i=1;i<=n;i++)if(!vis[i])find(i);
	fio<<ans;
	return 0;
}