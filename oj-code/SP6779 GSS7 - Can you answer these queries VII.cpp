#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
int ans1,ans2;
template<typename any>struct odt{
	struct odt_node{
		int l,r;mutable any data;
		odt_node(int _l,int _r=-1,any _data=0):l(_l),r(_r),data(_data){}
		bool operator<(const odt_node &t)const{return l<t.l;}
	};
	std::set<odt_node>s;
	auto insert(int _l,int _r,any _data){return s.insert(odt_node(_l,_r,_data));}
	auto begin(){return s.begin();}
	auto end(){return s.end();}
	auto split(int pos){
		auto it=s.lower_bound(pos);
		if(it!=s.end()&&it->l==pos)return it;
		it--;int l=it->l,r=it->r;any k=it->data;
		s.erase(it);insert(l,pos-1,k);
		return insert(pos,r,k).first;
	}
	auto assign(int l,int r,any k){
		auto it_r=split(r+1),it_l=split(l);
		s.erase(it_l,it_r);
		return insert(l,r,k).first;
	}
	any query(int l, int r){
		auto it_r=split(r+1),it_l=split(l);int q1=ans1,q2=ans1;
		it_r--;it_l--;
		for(auto it=it_r;it!=it_l;it--)q2+=(it->r-it->l+1)*it->data,q1=std::max(q1,q2),q2=std::max(q2,0);
		ans1=q2;return q1;
	}
};
odt<int>s;
constexpr int kN=100007;
std::vector<int>ed[kN];
int n,m,cnt,w[kN],fa[kN],gs[kN],rnk[kN],top[kN],sz[kN],dep[kN],dfn[kN];
void dfs1(int u){
	sz[u]=1;
	for(int v:ed[u]){
		if(v==fa[u])continue;
		fa[v]=u;sz[v]=1;dep[v]=dep[u]+1;
		dfs1(v);sz[u]+=sz[v];
		if(sz[v]>sz[gs[u]])gs[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;dfn[u]=++cnt;rnk[cnt]=u;
	if(!gs[u])return;else dfs2(gs[u],t);
	for(int v:ed[u])if(v!=fa[u]&&v!=gs[u])dfs2(v,v);
}
int tree_query(int x,int y){
	int res=0;while(top[x]!=top[y]){if(dep[top[x]]<dep[top[y]])std::swap(x,y),std::swap(ans1,ans2);res=std::max(res,s.query(dfn[top[x]],dfn[x]));x=fa[top[x]];}
	if(dep[x]>dep[y]){std::swap(x,y);std::swap(ans1,ans2);}std::swap(ans1,ans2);res=std::max(res,s.query(dfn[x],dfn[y]));return std::max(res,ans1+ans2);
}
void tree_assign(int x,int y,int k){
	while(top[x]!=top[y]){if(dep[top[x]]<dep[top[y]])std::swap(x,y);s.assign(dfn[top[x]],dfn[x],k);x=fa[top[x]];}
	if(dep[x]>dep[y]){std::swap(x,y);}s.assign(dfn[x],dfn[y],k);
}
signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
	fio>>n;for(int i=1;i<=n;i++)fio>>w[i];
	for(int i=1,u,v;i<n;i++)fio>>u>>v,ed[u].emplace_back(v),ed[v].emplace_back(u);
	dfs1(1);dfs2(1,1);s.insert(n+1,n+1,0);
	for(int i=1;i<=n;i++)s.insert(i,i,w[rnk[i]]);
	fio>>m;while(m--){
		int t,x,y;fio>>t>>x>>y;
		switch(t){
		case 1:ans1=ans2=0;fio<<tree_query(x,y)<<'\n';break;
		case 2:fio>>t;tree_assign(x,y,t);break;
		}
	}
	return fio.flush();
}