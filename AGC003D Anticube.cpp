#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<random>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define siz(x) int((x).size())
std::mt19937 rng(std::random_device{}());
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
class fastIO{private:char ibuf[50007],*p1=ibuf,*p2=ibuf,obuf[50007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,50007,stdin),p1==p2)?(file_end=true),char(EOF):*p1++;}void put(const char x){p3-obuf<50007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();!isgraph(t);t=get());return*this;}template<typename any>typename std::enable_if<std::is_same<any,char>::value,any>::type tpval(){char t;for(t=get();!isgraph(t);t=get());return t;}fastIO&operator>>(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return*this;}template<typename any>typename std::enable_if<std::is_same<any,std::string>::value,any>::type tpval(){std::string t;char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return t;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,any>::type tpval(){any t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return t;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,any>::type tpval(){any t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return t;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}template<typename any1,typename any2>std::pair<any1,any2>tpval(){return std::pair<any1,any2>(tpval<any1>(),tpval<any2>());}template<typename any>fastIO&read(any&t){return*this>>t;}fastIO&read(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}template<typename any,typename...args>fastIO&read(any&t1,args&...t2){return(*this>>t1).read(t2...);}fastIO&operator<<(const char t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=char(t%10+48),t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=char(t%10+48),t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}template<typename any>fastIO&write(const any&t){return*this<<t;}template<typename any,typename...args>fastIO&write(const any&t1,const args&...t2){return(*this<<t1).write(t2...);}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
using lolo=long long;
using i128=__int128_t;
using pii=std::pair<int,int>;
namespace math{
	inline lolo gcd(lolo x,lolo y){return y?gcd(y,x%y):x;}
	inline lolo qp(i128 a,lolo b,lolo MOD,lolo t=1){if(b==0)return 1;for(;b;b>>=1,a=a*a%MOD)if(b&1)t=lolo(a*t%MOD);return t;}
	inline auto abs(const auto &x){return x<0?-x:x;}
	bool isprime(lolo n){
		constexpr static int pr[]={2,325,9375,28178,450775,9780504,1795265022};
		if(n<2)return 0;
		lolo a,b,k,x=0,y=n-1;
		while(~y&1)x++,y>>=1;
		for(int i=0;i<7&&pr[i]<n;i++){
			a=pr[i],b=qp(a,y,n);
			for(int j=1;j<=x;j++){
				k=lolo(i128(b)*b%n);
				if(k==1&&b!=1&&b!=n-1)return 0;
				b=k;
			}
			if(b!=1)return 0;
		}
		return 1;
	}
	lolo get_factor(lolo n){
		lolo c=rng()%(n-1)+1,L=1,cnt=1,pre=0,x=c%n,y=lolo((i128(x)*x+c)%n),g=gcd(abs(x-y),n);
		if(g>1)return g;
		while(x!=y){
			for(int i=0;i<L;i++){
				x=lolo((i128(x)*x+c)%n),y=lolo((i128(y)*y+c)%n),y=lolo((i128(y)*y+c)%n);
				pre=lolo(i128(cnt)*abs(x-y)%n);
				if(x==y||!pre)break;
				cnt=pre;
			}
			g=gcd(cnt,n);
			if(g>1)return g;
			if(L<128)L<<=1;
		}
		return n;
	}
	void prime_dfs(lolo n,std::basic_string<lolo>&ans){
		if(n<2)return;
		if(isprime(n)){ans+=n;return;}
		if(n==4){(ans+=2)+=2;return;}
		lolo p=n;
		while(p>=n)p=get_factor(n);
		while(n%p==0)prime_dfs(p,ans),n/=p;
		prime_dfs(n,ans);
	}
	std::basic_string<lolo>factorization(lolo x){
		std::basic_string<lolo>ans;
		prime_dfs(x,ans);
		std::sort(ans.begin(),ans.end());
		return ans;
	}
}
using pli=std::pair<lolo,int>;
auto change(const std::basic_string<lolo>&a){
	std::vector<pli>b;
	for(auto i:a){
		if(b.empty())b.emplace_back(i,1);
		else if(i==b.back().first)b.back().second++;
		else b.emplace_back(i,1);
	}
	return b;
}
namespace pbds=__gnu_pbds;
#define int long long
constexpr int kN=1e5+1;
int n,ans;
lolo x[kN],y[kN];
template<typename any>
inline any ipow(any _a,int _b){
	any _t=1;
	while(_b--)_t*=_a;
	return _t;
}
pbds::gp_hash_table<lolo,int>mp;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n;
	for(int i=1,t;i<=n;i++){
		fio>>t;x[i]=y[i]=1;
		auto r=change(math::factorization(t));
		for(auto it:r)x[i]*=ipow(it.first,it.second-it.second/3*3);
		for(auto it:r)y[i]*=ipow(it.first,(3-it.second%3)%3);
		mp[x[i]]++;
	}
	if(mp[1]){ans++;}mp[1]=0;
	for(int i=1;i<=n;i++)ans+=std::max(mp[x[i]],mp[y[i]]),mp[x[i]]=mp[y[i]]=0;
	fio<<ans;
	return 0;
}