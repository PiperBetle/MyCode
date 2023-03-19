#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1){t=-t;}return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
constexpr int kN=1e5+7;
int a[kN],lmn[kN],rmn[kN];
long long sum[kN];
std::stack<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;fio>>n;long long ans=0;
	for(int i=1;i<=n;i++)fio>>a[i],sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(!q.empty()&&a[i]<a[q.top()])rmn[q.top()]=i-1,q.pop();
		q.push(i);
	}
	while(!q.empty())rmn[q.top()]=n,q.pop();
	for(int i=n;i>=1;i--){
		while(!q.empty()&&a[i]<a[q.top()])lmn[q.top()]=i+1,q.pop();
		q.push(i);
	}
	while(!q.empty())lmn[q.top()]=1,q.pop();
	for(int i=1;i<=n;i++)ans=std::max(ans,a[i]*(sum[rmn[i]]-sum[lmn[i]-1]));
	fio<<ans;
	return fio.flush();
}