#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?(file_end=true),EOF:*p1++;}void put(char x){p3-obuf<1000007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(char c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(char c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c-48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c-48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c-48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c-48);return*this;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}fastIO&operator<<(const char t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
constexpr int kN=10007;
int n,m,dfn[kN],low[kN],cnt,bl[kN],siz[kN],dfs_clock,in[kN],w[kN],val[kN],f[kN];
std::vector<int>g1[kN],g2[kN],b;
std::stack<int,std::vector<int>>s;
std::queue<int>q;
inline void chkmin(auto &x,auto y){if(y<x)x=y;}
inline void chkmax(auto &x,auto y){if(x<y)x=y;}
bool vis[kN];
void tarjan(int u){
	low[u]=dfn[u]=++dfs_clock;
	vis[u]=true;s.emplace(u);
	for(int v:g1[u])
		if(!dfn[v])tarjan(v),chkmin(low[u],low[v]);
		else if(vis[v])chkmin(low[u],dfn[v]);
	if(low[u]==dfn[u]){
		bl[u]=++cnt,vis[u]=false,siz[cnt]++;
		for(;s.top()!=u;s.pop())bl[s.top()]=cnt,vis[s.top()]=false,siz[cnt]++;
		s.pop();
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	memset(low+1,0x3f,sizeof(int)*n);fio>>n>>m;
	for(int i=1;i<=n;i++)fio>>w[i];
	for(int i=1,u,v;i<=m;i++)fio>>u>>v,g1[u].emplace_back(v);
	for(int i=1;i<=n;i++)if(!dfn[i])dfs_clock=0,tarjan(i);
	for(int u=1;u<=n;u++)for(int v:g1[u])if(bl[u]!=bl[v])in[bl[v]]++,g2[bl[u]].emplace_back(bl[v]);
	for(int i=1;i<=n;i++)val[bl[i]]+=w[i];
	memcpy(f+1,val+1,sizeof(int)*cnt);
	for(int i=1;i<=cnt;i++)if(!in[i])q.emplace(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		b.emplace_back(u);
		for(int v:g2[u])if(!--in[v])q.emplace(v);
	}
	for(int u:b)for(int v:g2[u])chkmax(f[v],f[u]+val[v]);
	fio<<*std::max_element(f+1,f+1+cnt);
	return 0;
}