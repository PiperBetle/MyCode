#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1,kM=2e5+1;
int n,m,k,ans[kN];
struct{
	int tr[kM];
	void updata(int _x,int _k){for(;_x<=k;_x+=_x&-_x)tr[_x]+=_k;}
	int query(int _x){int _k=0;for(;_x;_x-=_x&-_x)_k+=tr[_x];return _k;}
}tr;
struct node{
	int a,b,c,cnt,sum;
	auto operator<=>(const node &)const=default;
	bool operator==(const node &t)const{return a==t.a&&b==t.b&&c==t.c;};
}a[kN],b[kN],t[kN];
void CDQ(int l,int r){
	if(l==r)return;
	int d=(l+r)/2;
	CDQ(l,d),CDQ(d+1,r);
	int p1=l,p2=d+1,id=l;
	while(p1<=d&&p2<=r)
		if(a[p1].b<=a[p2].b)tr.updata(a[p1].c,a[p1].cnt),t[id++]=a[p1++];
		else a[p2].sum+=tr.query(a[p2].c),t[id++]=a[p2++];
	while(p1<=d)tr.updata(a[p1].c,a[p1].cnt),t[id++]=a[p1++];
	while(p2<=r)a[p2].sum+=tr.query(a[p2].c),t[id++]=a[p2++];
	for(int i=l;i<=d;i++)tr.updata(a[i].c,-a[i].cnt);
	for(int i=l;i<=r;i++)a[i]=t[i];
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>b[i].a>>b[i].b>>b[i].c;
	std::sort(b+1,b+1+n);
	for(int i=1,j=0;i<=n;i++)if(j++,b[i]!=b[i+1])
		a[++m]=b[i],a[m].cnt=j,j=0;
	CDQ(1,m);
	for(int i=1;i<=m;i++)ans[a[i].sum+a[i].cnt-1]+=a[i].cnt;
	for(int i=0;i<n;i++)cout<<ans[i]<<'\n';
	return 0;
}