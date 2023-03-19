#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<climits>
#include<set>
#include<ext/pb_ds/assoc_container.hpp>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
class fastIO{private:char ibuf[50007],*p1=ibuf,*p2=ibuf,obuf[50007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,50007,stdin),p1==p2)?(file_end=true),char(EOF):*p1++;}void put(const char x){p3-obuf<50007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();!isgraph(t);t=get());return*this;}template<typename any>typename std::enable_if<std::is_same<any,char>::value,any>::type tpval(){char t;for(t=get();!isgraph(t);t=get());return t;}fastIO&operator>>(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return*this;}template<typename any>typename std::enable_if<std::is_same<any,std::string>::value,any>::type tpval(){std::string t;char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return t;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,any>::type tpval(){any t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return t;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,any>::type tpval(){any t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return t;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}template<typename any1,typename any2>std::pair<any1,any2>tpval(){return std::pair<any1,any2>(tpval<any1>(),tpval<any2>());}template<typename any>fastIO&read(any&t){return*this>>t;}fastIO&read(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}template<typename any,typename...args>fastIO&read(any&t1,args&...t2){return(*this>>t1).read(t2...);}fastIO&operator<<(const char t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=char(t%10+48),t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=char(t%10+48),t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}template<typename any>fastIO&write(const any&t){return*this<<t;}template<typename any,typename...args>fastIO&write(const any&t1,const args&...t2){return(*this<<t1).write(t2...);}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
#define cin fio
#define cout fio
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
namespace pbds=__gnu_pbds;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e6+1;
template<typename any>
struct vector{
	any *len,a[7];
	vector(){len=a;}
	vector &operator+=(int x){
		*(len++)=x;
		return *this;
	}
	any *begin(){return a;}
	any *end(){return len;}
};
int n,q,nxt[N],min[N<<2];
bool pr[N],tag[N<<2];
pbds::tree<int,pbds::null_type>set[N];
vector<int>vec[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void updata(int u,int l,int r,int x,int k){
	if(l==r){min[u]=k;return;}
	x<=mid?updata(ls,l,mid,x,k):updata(rs,mid+1,r,x,k);
	min[u]=std::min(min[ls],min[rs]);
}
void updata(int x){
	int res=INT_MAX;
	for(int y:vec[x])if(auto it=set[y].upper_bound(x);it!=set[y].end())res=std::min(res,*it);
	updata(1,1,n,x,res);
}
void updata(int u,int l,int r,int x){
	if(l==r){
		if(!tag[u]){
			tag[u]=true;
			for(int y:vec[x]){
				auto it=set[y].insert(x).first;
				if(it!=set[y].begin())updata(*--it);
			}
			updata(x);
		}else{
			min[u]=INT_MAX;
			tag[u]=false;
			for(int y:vec[x]){
				set[y].erase(x);auto it=set[y].lower_bound(x);
				if(it!=set[y].begin())updata(*--it);
			}
		}
		return;
	}
	x<=mid?updata(ls,l,mid,x):updata(rs,mid+1,r,x);
	min[u]=std::min(min[ls],min[rs]);
}
int query(int u,int l,int r,int x,int y){
	if(x<=l&&r<=y)return min[u];
	int res=INT_MAX;
	if(x<=mid)res=std::min(res,query(ls,l,mid,x,y));
	if(y>mid)res=std::min(res,query(rs,mid+1,r,x,y));
	return res;
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>q;
	for(int i=2;i<=n;++i)if(!pr[i])for(int j=i;j<=n;j+=i)vec[j]+=i,pr[j]=true;
	memset(min+1,0x3f,sizeof(int)*(n<<2));
	std::string str;for(int l,r;q--;)switch(cin>>str>>l,str.front()){
	case 'S':updata(1,1,n,l);break;
	case 'C':cin>>r;cout<<(query(1,1,n,l,r)<=r?"DA\n":"NE\n");break;
	}
	return 0;
}