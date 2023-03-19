#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?file_end=true:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:explicit operator bool(){return!file_end;}int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(char c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(char c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}}fio;
constexpr int kN=5007,inf=0x3f3f3f3f;
int n,m,k,dis[2][kN],mn1,mn2=inf,deg[kN];
bool vis[kN];
struct edge{int v,t;};
std::vector<edge>ed[kN];
void SPFA(int stt,int op){
	std::queue<int>q;
	int (&dis)[kN]=::dis[op];
	memset(vis+1,0,sizeof(bool)*n);
	memset(dis+1,0x3f,sizeof(int)*n);
	for(q.emplace(stt),vis[stt]=true,dis[stt]=0;!q.empty();){
		int u=q.front();q.pop();
		vis[u]=false;
		for(auto[v,t]:ed[u]){
			if(dis[u]+t<dis[v]&&deg[v]>=k){
				dis[v]=dis[u]+t;
				if(!vis[v])q.emplace(v),vis[v]=true;
			}
		}
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n>>m>>k;
	for(int i=1,u,v,t;i<=m;i++)fio>>u>>v>>t,ed[u].emplace_back(v,t),ed[v].emplace_back(u,t);
	for(int u=2;u<n;u++){
		for(auto[v,t]:ed[u])if(!vis[v])vis[v]=true,deg[u]++;
		for(auto[v,t]:ed[u])vis[v]=false;
	}
	deg[1]=deg[n]=inf;SPFA(1,0);SPFA(n,1);mn1=dis[0][n];
	for(int u=1;u<=n;u++){
		if(deg[u]<k)continue;
		for(auto[v,t]:ed[u])if(int len=dis[0][u]+t+dis[1][v];len>mn1&&deg[v]>=k)mn2=std::min(mn2,len);
	}
	fio<<(mn2==inf?-1:mn2);
	return fio.flush();
}