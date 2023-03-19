#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#include<numeric>
class fastIO{private:char ibuf[50007],*p1=ibuf,*p2=ibuf,obuf[50007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,50007,stdin),p1==p2)?(file_end=true),char(EOF):*p1++;}void put(const char x){p3-obuf<50007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();!isgraph(t);t=get());return*this;}template<typename any>typename std::enable_if<std::is_same<any,char>::value,any>::type tpval(){char t;for(t=get();!isgraph(t);t=get());return t;}fastIO&operator>>(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return*this;}template<typename any>typename std::enable_if<std::is_same<any,std::string>::value,any>::type tpval(){std::string t;char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return t;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,any>::type tpval(){any t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return t;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,any>::type tpval(){any t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return t;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}template<typename any1,typename any2>std::pair<any1,any2>tpval(){return std::pair<any1,any2>(tpval<any1>(),tpval<any2>());}template<typename any>fastIO&read(any&t){return*this>>t;}fastIO&read(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}template<typename any,typename...args>fastIO&read(any&t1,args&...t2){return(*this>>t1).read(t2...);}fastIO&operator<<(const char t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=char(t%10+48),t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=char(t%10+48),t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}template<typename any>fastIO&write(const any&t){return*this<<t;}template<typename any,typename...args>fastIO&write(const any&t1,const args&...t2){return(*this<<t1).write(t2...);}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
#define siz(x) loli((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<loli,loli>;
using inlsi=const std::initializer_list<loli>&;
// constexpr venti operator""_vt(uloli x){return venti(x);}
std::multiset<loli>s;
loli n,m,a[100007],p[100007],c[100007],d[100007],t1[100007],t2[100007];
inline void exgcd(loli a,loli b,loli &x,loli &y){if(!b){x=1,y=0;return;}exgcd(b,a%b,y,x);y-=a/b*x;}
inline loli qm(loli a,loli b,uloli p){uloli c=(uloli)a*b-(uloli)(1.l*a/p*b+.5l)*p;return c<p?c:c+p;}
// inline loli qm(loli a,loli b,uloli p){return loli(venti(a)*b%p);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	loli T;fio>>T;while(T--){
		fio>>n>>m;s.clear();
		for(loli i=1;i<=n;i++)fio>>a[i];
		for(loli i=1;i<=n;i++)fio>>p[i];
		for(loli i=1;i<=n;i++)fio>>c[i];
		for(loli i=1,t;i<=m;i++)fio>>t,s.insert(t);
		for(loli i=1;i<=n;i++){
			auto it=*s.begin()>a[i]?s.begin():--s.upper_bound(a[i]);
			d[i]=*it;s.erase(it);s.insert(c[i]);
		}
		bool f=true;for(loli i=1;i<=n;i++)if(p[i]!=1)f=false;
		if(f){loli ans=0;for(loli i=1;i<=n;i++)ans=std::max(ans,(a[i]-1)/d[i]+1);fio<<ans;goto ctn;}
		for(loli i=1;i<=n;i++){
			loli g=std::gcd(d[i],p[i]);
			if(a[i]%g){fio<<"-1";goto ctn;}
			loli x,y;exgcd(d[i],p[i],x,y);
			t2[i]=p[i]/g;t1[i]=qm(a[i]/g,(x%t2[i]+t2[i])%t2[i],t2[i]);
		}
		for(loli i=1;i<n;i++){
			loli g=std::gcd(t2[i],t2[i+1]);
			if((t1[i+1]-t1[i])%g){fio<<"-1";goto ctn;}
			loli x,y;exgcd(t2[i]/g,t2[i+1]/g,x,y); 
			loli n1=qm(x,(t1[i+1]-t1[i])/g,t2[i+1]/g),n2=t2[i]/g*t2[i+1];
			n1=(qm(n1,t2[i],n2)+t1[i])%n2;t1[i+1]=n1;t2[i+1]=n2;
		}
		fio<<t1[n];ctn:fio<<'\n';
	}
	return 0;
}