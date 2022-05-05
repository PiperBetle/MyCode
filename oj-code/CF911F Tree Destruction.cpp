#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?file_end=true:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:explicit operator bool(){return!file_end;}int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(char c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(char c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}}fio;
constexpr int kN=2e5+7;
std::vector<int>ed[kN],bfn;
std::queue<int>q;
int dep1[kN],dep2[kN],fa[kN];
bool dim[kN],vis[kN];
void dfs1(int u,int &m){
	for(int v:ed[u]){
		if(v==fa[u])continue;
		if((dep1[v]=dep1[u]+1)>dep1[m])m=v;
		fa[v]=u;dfs1(v,m);
	}
}
void dfs2(int u,int fa){
	for(int v:ed[u]){
		if(v==fa)continue;
		dep2[v]=dep2[u]+1;
		dfs2(v,u);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m1=0,m2=0;long long ans=0;fio>>n;
	for(int i=1,u,v;i<n;i++)fio>>u>>v,ed[u].emplace_back(v),ed[v].emplace_back(u);
	dfs1(1,m1);dep1[m1]=fa[m1]=0;dfs1(m1,m2);dfs2(m2,0);
	for(int p=m2;p;p=fa[p])dim[p]=true;
	for(q.emplace(m1);!q.empty();){
		int u=q.front();q.pop();
		bfn.emplace_back(u);
		for(int v:ed[u])if(v!=fa[u])q.emplace(v);
	}
	std::reverse(bfn.begin(),bfn.end());
	for(int p:bfn)if(!dim[p])ans+=std::max(dep1[p],dep2[p]);
	for(int p=m2;p!=m1;p=fa[p])ans+=dep1[p];
	fio<<ans<<'\n';
	for(int p:bfn)if(!dim[p]){if(dep1[p]>dep2[p])fio<<m1<<' '<<p<<' '<<p<<'\n';else fio<<m2<<' '<<p<<' '<<p<<'\n';}
	for(int p=m2;p!=m1;p=fa[p])fio<<m1<<' '<<p<<' '<<p<<'\n';
	return fio.flush();
}