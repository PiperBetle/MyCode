#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
class fastIO{private:char ibuf[50007],*p1=ibuf,*p2=ibuf,obuf[50007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,50007,stdin),p1==p2)?(file_end=true),char(EOF):*p1++;}void put(const char x){p3-obuf<50007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();!isgraph(t);t=get());return*this;}template<typename any>typename std::enable_if<std::is_same<any,char>::value,any>::type tpval(){char t;for(t=get();!isgraph(t);t=get());return t;}fastIO&operator>>(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return*this;}template<typename any>typename std::enable_if<std::is_same<any,std::string>::value,any>::type tpval(){std::string t;char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return t;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,any>::type tpval(){any t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return t;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,any>::type tpval(){any t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return t;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}template<typename any1,typename any2>std::pair<any1,any2>tpval(){return std::pair<any1,any2>(tpval<any1>(),tpval<any2>());}template<typename any>fastIO&read(any&t){return*this>>t;}fastIO&read(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}template<typename any,typename...args>fastIO&read(any&t1,args&...t2){return(*this>>t1).read(t2...);}fastIO&operator<<(const char t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=char(t%10+48),t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=char(t%10+48),t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}template<typename any>fastIO&write(const any&t){return*this<<t;}template<typename any,typename...args>fastIO&write(const any&t1,const args&...t2){return(*this<<t1).write(t2...);}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=100001;
inline venti gcd(venti x,venti y){return y?gcd(y,x%y):x;}
inline venti lcm(venti x,venti y){return x/gcd(x,y)*y;}
struct frac{
	venti up,dw;
	frac(venti a=0,venti b=1):up(a),dw(b){}
	frac operator+(){return frac(+up,+dw);}
	frac operator~(){return frac(dw,up);}
	frac &updata(){venti g=gcd(up,dw);up/=g,dw/=g;return *this;}
	friend void operator|(frac &x,frac &y){venti l=lcm(x.dw,y.dw);x.up*=l/x.dw;y.up*=l/y.dw;x.dw=y.dw=l;}
	friend frac operator+(frac x,frac y){x|y;x.up+=y.up;return x.updata();}
	friend frac &operator+=(frac &x,frac y){x|y;x.up+=y.up;return x.updata();}
	friend frac operator*(frac x,frac y){return frac(x.up*y.up,x.dw*y.dw).updata();}
	friend frac &operator*=(frac&x,frac y){return x=frac(x.up*y.up,x.dw*y.dw).updata();}
	friend frac operator/(frac x,frac y){return frac(x.up*y.dw,x.dw*y.up).updata();}
	friend frac &operator/=(frac &x,frac y){return x=frac(x.up*y.dw,x.dw*y.up).updata();}
	template<typename any>friend any &operator<<(any &x,const frac &y){return x<<y.up<<' '<<y.dw;}
}ans[kN];
std::basic_string<int>g[kN];
int n,m,in[kN];
std::queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n>>m;
	for(int i=1,t,v;i<=n;i++)for(fio>>t;t--;)fio>>v,g[i]+=v,in[v]++;
	for(int i=1;i<=m;i++)ans[i].up=1;
	for(int i=1;i<=n;i++)if(!in[i])q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(!g[u].empty())ans[u]/=frac(siz(g[u]));
		for(int v:g[u]){
			ans[v]+=ans[u];
			if(!--in[v])q.push(v);
		}
	}
	for(int i=1;i<=n;i++)if(g[i].empty())fio<<ans[i]<<'\n';
	return 0;
}