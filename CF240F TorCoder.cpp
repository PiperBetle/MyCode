	//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
	#include<iostream>
	#include<cstdio>
	#include<algorithm>
	#include<cstring>
	#include<cassert>
	#include<tuple>
	#define siz(x) int((x).size())
	#define cauto const auto
	#define all(x) (x).begin(),(x).end()
	#define fi first
	#define se second
	using std::cin;using std::cout;
	using std::max;using std::min;
	using std::tie;using std::ignore;
	template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
	template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
	template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
	template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
	using loli=long long;
	using uloli=unsigned long long;
	using lodb=long double;
	using venti=__int128_t;
	using pii=std::pair<int,int>;
	using inlsi=const std::initializer_list<int>&;
	using bsi=std::basic_string<int>;
	using bsc=std::basic_string<char>;
	constexpr venti operator""_vt(uloli x){return venti(x);}
	constexpr int N=1e5+5;
	int n,m,cnt[26];
	bsc a;
	struct{
		int sum[N<<2],tag[N<<2];
		char c;
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
		void pushup(int u){sum[u]=sum[ls]+sum[rs];}
		void mark(int u,int l,int r,int k){tag[u]=k;sum[u]=k*(r-l+1);}
		void pushdown(int u,int l,int r){
			if(tag[u]==-1)return;
			mark(ls,l,mid,tag[u]);mark(rs,mid+1,r,tag[u]);
			tag[u]=-1;
		}
		void build(int u,int l,int r){
			tag[u]=-1;
			if(l==r){sum[u]=a[l]==c;return;}
			build(ls,l,mid);build(rs,mid+1,r);
			pushup(u);
		}
		void assign(int u,int l,int r,int x,int y,int k){
			if(x<=l&&r<=y)return mark(u,l,r,k);
			pushdown(u,l,r);
			if(x<=mid)assign(ls,l,mid,x,y,k);
			if(y>mid)assign(rs,mid+1,r,x,y,k);
			pushup(u);
		}
		int query(int u,int l,int r,int x,int y){
			if(x<=l&&r<=y)return sum[u];
			pushdown(u,l,r);
			int k=0;
			if(x<=mid)k+=query(ls,l,mid,x,y);
			if(y>mid)k+=query(rs,mid+1,r,x,y);
			return k;
		}
		void print(int u,int l,int r){
			if(l==r){if(sum[u])a[l]=c;return;}
			pushdown(u,l,r);
			print(ls,l,mid);print(rs,mid+1,r);
		}
	#undef ls
	#undef rs
	#undef mid
	}s[26];
	signed main(){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		std::ios::sync_with_stdio(false);cin.tie(nullptr);
		for(int i=0;i<26;i++)s[i].c=char(i+'a');
		cin>>n>>m>>a;a=' '+a;
		for(int i=0;i<26;i++)s[i].build(1,1,n);
		for(int l,r,k;m--;){
			cin>>l>>r;k=0;
			for(int i=0;i<26;i++)if((cnt[i]=s[i].query(1,1,n,l,r))&1)k++;
			if(k>1)continue;else for(int i=0;i<26;i++)s[i].assign(1,1,n,l,r,0);
			if(k==1){for(int i=0;i<26;i++)if(cnt[i]&1){cnt[k=i]--;break;}}else k=-1;
			for(int i=0;i<26;i++)if(cnt[i])
				s[i].assign(1,1,n,l,l+cnt[i]/2-1,1),l+=cnt[i]/2,
				s[i].assign(1,1,n,r-cnt[i]/2+1,r,1),r-=cnt[i]/2;
			if(~k)s[k].assign(1,1,n,l,r,1);
		}
		for(int i=0;i<26;i++)s[i].print(1,1,n);
		for(int i=1;i<=n;i++)cout<<a[i];	
		return 0;
	}