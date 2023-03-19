#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
std::vector<int>s[300007];
int f[300007],d[300007],c;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int u,int fa){
	int d1=0,d2=0;
	for(auto v:s[u]){
		if(v==fa)continue;else dfs(v,u);
		d[u]=std::max(d[u],d[v]+1);
		if(d[v]+1>d1)d2=d1,d1=d[v]+1;
		else if(d[v]+1>d2)d2=d[v]+1;
	}
	c=std::max(c,d1+d2);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m,q,u,v,t,x,y,fx,fy;
	fio>>n>>m>>q;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		fio>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u);
		fx=find(u),fy=find(v);
		if(fx!=fy)f[fx]=fy;
	}
	for(int i=1;i<=n;i++)if(find(i)==i)dfs(i,c=0),d[i]=c;
	while(q--){
		fio>>t>>x;
		if(t==1){fio<<d[find(x)]<<'\n';continue;}else fio>>y,fx=find(x),fy=find(y);
		if(fx!=fy)d[f[fx]=fy]=std::max({d[fx],d[fy],((d[fx]+1)>>1)+((d[fy]+1)>>1)+1});
	}
	return fio.flush();
}