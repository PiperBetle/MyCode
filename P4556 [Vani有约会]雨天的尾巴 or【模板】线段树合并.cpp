#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?(file_end=true),EOF:*p1++;}void put(const char x){p3-obuf<1000007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();!isgraph(t);t=get());return*this;}template<typename any>typename std::enable_if<std::is_same<any,char>::value,any>::type tpval(){char t;for(t=get();!isgraph(t);t=get());return t;}fastIO&operator>>(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return*this;}template<typename any>typename std::enable_if<std::is_same<any,std::string>::value,any>::type tpval(){std::string t;char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return t;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,any>::type tpval(){any t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return t;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,any>::type tpval(){any t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return t;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}template<typename any1,typename any2>std::pair<any1,any2>tpval(){return std::pair<any1,any2>(tpval<any1>(),tpval<any2>());}template<typename any>fastIO&read(any&t){return*this>>t;}fastIO&read(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}template<typename any,typename...args>fastIO&read(any&t1,args&...t2){return(*this>>t1).read(t2...);}fastIO&operator<<(const char t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}template<typename any>fastIO&write(const any&t){return*this<<t;}template<typename any,typename...args>fastIO&write(const any&t1,const args&...t2){return(*this<<t1).write(t2...);}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
constexpr int N=1e5,kN=N+7,kZ=kN*std::__lg(kN)*4;
std::basic_string<int>g[kN];
int n,m,fp,fa[kN],dep[kN],gs[kN],top[kN],sz[kN],rt[kN],ans[kN];
void dfs1(int u){
	for(int v:g[u]){
		if(v==fa[u])continue;
		fa[v]=u,dep[v]=dep[u]+1,sz[v]=1;
		dfs1(v);sz[u]+=sz[v];
		if(sz[v]>sz[gs[u]])gs[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;if(!gs[u])return;else dfs2(gs[u],t);
	for(int v:g[u])if(v!=fa[u]&&v!=gs[u])dfs2(v,v);
}
inline int LCA(int x,int y){
	for(;top[x]!=top[y];x=fa[top[x]])if(dep[top[x]]<dep[top[y]])std::swap(x,y);
	return dep[x]<dep[y]?x:y;
}
struct stn{int ls=0,rs=0,max,pos;}s[kZ];
#define nls (s[now].ls)
#define nrs (s[now].rs)
#define mid ((l+r)>>1)
void pushup(int now){
	s[now].max=std::max(s[nls].max,s[nrs].max);
	s[now].pos=(s[nls].max==s[nrs].max?std::min(s[nls].pos,s[nrs].pos):(s[nls].max>s[nrs].max?s[nls].pos:s[nrs].pos));
}
void updata(int &now,int l,int r,int x,int k){
	if(!now)now=++fp;
	if(l==r){s[now].max+=k;s[now].pos=l;return;}
	x<=mid?updata(s[now].ls,l,mid,x,k):updata(s[now].rs,mid+1,r,x,k);
	pushup(now);
}
int merge(int x,int y,int l,int r){
	if(!x||!y)return x|y;
	if(l==r)return s[x].max+=s[y].max,s[x].pos=l,x;
	s[x].ls=merge(s[x].ls,s[y].ls,l,mid);
	s[x].rs=merge(s[x].rs,s[y].rs,mid+1,r);
	pushup(x);return x;
}
void dfs3(int u){
	for(int v:g[u]){
		if(v==fa[u])continue;
		dfs3(v);
		rt[u]=merge(rt[u],rt[v],1,N);
	}
	if(s[rt[u]].max)ans[u]=s[rt[u]].pos;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n>>m;
	for(int i=1,u,v;i<n;i++)fio>>u>>v,g[u]+=v,g[v]+=u;
	dep[1]=sz[1]=1;dfs1(1);dfs2(1,1);
	for(int u,v,t,p;m--;){
		fio>>u>>v>>t;p=LCA(u,v);
		updata(rt[u],1,N,t,1);
		updata(rt[v],1,N,t,1);
		updata(rt[p],1,N,t,-1);
		if(fa[p])updata(rt[fa[p]],1,N,t,-1);
	}
	dfs3(1);for(int i=1;i<=n;i++)fio<<ans[i]<<'\n';
	return 0;
}