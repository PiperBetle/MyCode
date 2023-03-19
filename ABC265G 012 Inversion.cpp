#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
#define siz(x)int((x).size())
#define cauto const auto
#define all(x)(x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
const int N=100001,M=400001;
int n,q,t[3],a[N],l0,l1,l2;
struct{
	int sum[M][3],cnt[M][3][3],lst[M][3],tag[M];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
	void push_up(int u){
		for(int i=0;i<3;i++)sum[u][i]=sum[ls][i]+sum[rs][i];
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)
			if(i!=j)cnt[u][i][j]=cnt[ls][i][j]+cnt[rs][i][j]+sum[ls][i]*sum[rs][j];
	}
	void build(int u,int l,int r){
		for(int i=0;i<3;i++)lst[u][i]=i;
		if(l==r){sum[u][a[l]]=1;return;}
		build(ls,l,mid);build(rs,mid+1,r);
		push_up(u);
	}
	void work(int u,int *q){
		static int _sum[3],_cnt[3][3];
		memset(_sum,0,sizeof _sum);
		memset(_cnt,0,sizeof _cnt);
		for(int i=0;i<3;i++)lst[u][i]=q[lst[u][i]];
		tag[u]=1;
		for(int i=0;i<3;i++)_sum[q[i]]+=sum[u][i];
		for(int i=0;i<3;i++)sum[u][i]=_sum[i];
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(q[i]!=q[j])_cnt[q[i]][q[j]]+=cnt[u][i][j];
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)cnt[u][i][j]=_cnt[i][j];
	}
	void push_down(int u){
		work(ls,lst[u]);
		work(rs,lst[u]);
		tag[u]=0;
		for(int i=0;i<3;i++)lst[u][i]=i;
	}
	void updata(int u,int l,int r,int x,int y){
		if(x<=l&&r<=y){work(u,t);tag[u]=1;return;}
		if(tag[u])push_down(u);
		if(x<=mid)updata(ls,l,mid,x,y);
		if(y>mid)updata(rs,mid+1,r,x,y);
		push_up(u);
	}
	int query(int u,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			int res=cnt[u][1][0]+cnt[u][2][0]+cnt[u][2][1]+l1*sum[u][0]+l2*sum[u][0]+l2*sum[u][1];
			l0+=sum[u][0],l1+=sum[u][1],l2+=sum[u][2];
			return res;
		}
		if(tag[u])push_down(u);
		int res=0;
		if(x<=mid)res+=query(ls,l,mid,x,y);
		if(y>mid)res+=query(rs,mid+1,r,x,y);
		return res;
	}
#undef ls
#undef rs
#undef mid
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	s.build(1,1,n);
	for(int i=1,op,l,r;i<=q;i++){
		cin>>op;
		if(op==1){
			l0=l1=l2=0;
			cin>>l>>r;
			cout<<s.query(1,1,n,l,r)<<'\n';
		}else{
			cin>>l>>r>>t[0]>>t[1]>>t[2];
			s.updata(1,1,n,l,r);
		}
	}
	return 0;
}