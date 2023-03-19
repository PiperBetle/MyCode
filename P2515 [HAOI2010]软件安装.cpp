#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?(file_end=true),EOF:*p1++;}void put(char x){p3-obuf<1000007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();!isgraph(t);t=get());return*this;}fastIO&operator>>(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c-48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c-48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c-48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c-48);return*this;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}fastIO&operator<<(const char t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
inline void chkmin(auto &x,auto y){if(y<x)x=y;}
inline void chkmax(auto &x,auto y){if(x<y)x=y;}
constexpr int kN=507;
std::basic_string<int>g[kN];
std::stack<int>s;
int n,m,w0[kN],c0[kN],dfs_clock,low[kN],dfn[kN],cnt,bl[kN],w1[kN],c1[kN],nd[kN],in[kN],f[kN][kN];
bool vis[kN];
void tarjan(int u){
	low[u]=dfn[u]=++dfs_clock;
	vis[u]=true;s.emplace(u);
	for(int v:g[u])
		if(!dfn[v])tarjan(v),chkmin(low[u],low[v]);
		else if(vis[v])chkmin(low[u],dfn[v]);
	if(low[u]==dfn[u]){
		bl[u]=++cnt,vis[u]=false;
		for(;s.top()!=u;s.pop())bl[s.top()]=cnt,vis[s.top()]=false;
		s.pop();
	}
}
void dp(int u){
	for(int i=c1[u];i<=m;i++)f[u][i]=w1[u];
	for(int v:g[u]){
		dp(v);
		for(int i=m-c1[u];i>=0;i--)for(int j=0;j<=i;j++)
			chkmax(f[u][i+c1[u]],f[v][j]+f[u][i+c1[u]-j]);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n>>m;
	for(int i=1;i<=n;i++)fio>>c0[i];
	for(int i=1;i<=n;i++)fio>>w0[i];
	for(int i=1;i<=n;i++)if(fio>>nd[i],nd[i])g[nd[i]]+=i;
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++){
		w1[bl[i]]+=w0[i];c1[bl[i]]+=c0[i];
		if(bl[i]!=bl[nd[i]])g[bl[nd[i]]]+=bl[i],in[bl[i]]++;
	}
	for(int i=1;i<=cnt;i++)if(!in[i])g[0]+=i;
	dp(0);fio<<f[0][m];
	return 0;
}