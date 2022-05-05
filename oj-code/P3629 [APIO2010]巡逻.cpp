#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}~fastIO(){flush();}}fio;
constexpr int kN=1e5+7;
struct edge{int v,t;};
std::vector<edge>s[kN];
int dep[kN],fa[kN];
bool edi[kN];
void dfs(int u,int &m){
	for(auto[v,t]:s[u]){
		if(v==fa[u])continue;
		if((dep[v]=dep[u]+t)>dep[m])m=v;
		fa[v]=u;dfs(v,m);
	}
}
void dp(int u,int &m){
	for(auto[v,t]:s[u]){
		if(v==fa[u])continue;
		dp(v,m);
		m=std::max(m,t+dep[u]+dep[v]);
		dep[u]=std::max(dep[u],dep[v]+t);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,k,m1=0,m2=0;fio>>n>>k;
	for(int i=1,u,v;i<n;i++)fio>>u>>v,s[u].emplace_back(v,1),s[v].emplace_back(u,1);
	dfs(1,m1);dep[m1]=fa[m1]=0;dfs(m1,m2);
	int ans=((n-1)<<1)-(dep[m2]-1);
	if(k==2){
		while(m2)edi[m2]=true,m2=fa[m2];
		for(int u=1;u<=n;u++)if(edi[u])for(auto&[v,t]:s[u])if(edi[v])t=-1;
		m2=0;std::fill_n(dep+1,n,0);
		dp(m1,m2);ans-=m2-1;
	}
	fio<<ans;
	return 0;
}