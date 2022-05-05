#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
constexpr int kN=100007,kM=std::__lg(kN)+1;
std::vector<int>s[kN];
int n,m,q,dep[kN],p[kN][kM];
void dfs(int u,int f){
	for(int i=1;(1<<i)<=dep[u];i++)p[u][i]=p[p[u][i-1]][i-1];
	for(int v:s[u])if(v!=f)dep[v]=dep[u]+1,p[v][0]=u,dfs(v,u);
}
int LCA(int a,int b){
	if(dep[a]>dep[b])std::swap(a,b);
	for(int i=m;i>=0;i--)if(dep[a]+(1<<i)<=dep[b])b=p[b][i];
	if(a==b)return a;
	for(int i=m;i>=0;i--)if(p[a][i]!=p[b][i])a=p[a][i],b=b[p][i];
	return p[a][0];
}
inline int dis(int a,int b){return dep[a]+dep[b]-dep[LCA(a,b)]*2;}
inline int dis(int a,int b,int c){return dep[a]+dep[b]-dep[c]*2;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n>>q;m=std::__lg(n);
	for(int i=1,u,v;i!=n;i++)fio>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u);
	dfs(1,0);while(q--){
		int x1,y1,x2,y2,l1,l2;fio>>x1>>y1>>x2>>y2;l1=LCA(x1,y1),l2=LCA(x2,y2);
		fio<<(dis(x1,l2)+dis(y1,l2)==dis(x1,y1,l1)||dis(x2,l1)+dis(y2,l1)==dis(x2,y2,l2)?'Y':'N')<<'\n';
	}
	return fio.flush();
}