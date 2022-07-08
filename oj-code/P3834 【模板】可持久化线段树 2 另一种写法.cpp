#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?(file_end=true),EOF:*p1++;}void put(const char x){p3-obuf<1000007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();!isgraph(t);t=get());return*this;}template<typename any>typename std::enable_if<std::is_same<any,char>::value,any>::type tpval(){char t;for(t=get();!isgraph(t);t=get());return t;}fastIO&operator>>(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return*this;}template<typename any>typename std::enable_if<std::is_same<any,std::string>::value,any>::type tpval(){std::string t;char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return t;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,any>::type tpval(){any t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+c-48;if(y==1)t=-t;return t;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,any>::type tpval(){any t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+c-48;return t;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}template<typename any1,typename any2>std::pair<any1,any2>tpval(){return std::pair<any1,any2>(tpval<any1>(),tpval<any2>());}template<typename any>fastIO&read(any&t){return*this>>t;}fastIO&read(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}template<typename any,typename...args>fastIO&read(any&t1,args&...t2){return(*this>>t1).read(t2...);}fastIO&operator<<(const char t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}template<typename any>fastIO&write(const any&t){return*this<<t;}template<typename any,typename...args>fastIO&write(const any&t1,const args&...t2){return(*this<<t1).write(t2...);}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
constexpr int kN=2e5+7,kZ=2*std::__lg(kN)*kN;
int n,m,ed,a[kN],b[kN],rt[kN],len=0;
struct stn{int ls,rs,data;}s[kZ];
#define nls (s[now].ls)
#define nrs (s[now].rs)
#define mid ((l+r)>>1)
void updata(int &now,int pre,int x,int l,int r){
	s[now=++len]=s[pre];s[now].data++;
	if(l==r)return;
	x<=mid?updata(nls,s[pre].ls,x,l,mid):updata(nrs,s[pre].rs,x,mid+1,r);
}
int query(int now,int pre,int k,int l,int r){
	if(l==r)return b[l];
	int x=s[s[pre].ls].data-s[nls].data;
	return x>=k?query(nls,s[pre].ls,k,l,mid):query(nrs,s[pre].rs,k-x,mid+1,r);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n>>m;
	for(int i=1;i<=n;i++)a[i]=b[i]=fio.tpval<int>();
	std::sort(b+1,b+1+n);ed=std::unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++)updata(rt[i],rt[i-1],std::lower_bound(b+1,b+1+ed,a[i])-b,1,ed);
	for(int l,r,k;m--;)fio>>l>>r>>k<<query(rt[l-1],rt[r],k,1,ed)<<'\n';
	return 0;
}