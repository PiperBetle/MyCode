#include<iostream>
#include<cstdio>
#include<algorithm>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
constexpr int N=1e6,MOD=1e9+7;
inline auto calc(auto x){return x*(x+1)>>1;}
inline auto sqrcalc(auto x){return x*(x+1)*(x*2+1)/6;}
int n,m,f[N+7],sum[N+7],isum[N+7],sqrisum[N+7];
long long s[N+7];
int cnt,pt[100007],phi[N+7];
bool pr[N+7];
signed main(){
//	freopen("chess.in","r",stdin);
//	freopen("chess.out","w",stdout);
	pr[1]=true,phi[1]=1;
	for(int i=2;i<=N;++i){
		if(!pr[i])pt[++cnt]=i,phi[i]=i-1;
		for(int j=1;j<=cnt&&i*pt[j]<=N;++j){
			pr[i*pt[j]]=1;
			if(i%pt[j]==0){phi[i*pt[j]]=phi[i]*pt[j];break;}
			phi[i*pt[j]]=phi[i]*(pt[j]-1);
		}
	}
	for(int i=1;i<=N;++i)for(int j=1;j*i<=N;++j)s[i*j]+=1ll*phi[i]*j%MOD;
	for(long long i=1;i<=N;++i){
		f[i]=(i*i*i-2*i*calc(i-1)+2*sqrcalc(i-1)-2*i*i+2*s[i])%MOD;
		sum[i]=(sum[i-1]+f[i])%MOD;
		isum[i]=(isum[i-1]+f[i]*i)%MOD;
		sqrisum[i]=(sqrisum[i-1]+f[i]*i%MOD*i)%MOD;
	}
	int T;fio>>T;while(T--){
		fio>>n>>m;
		if(n>m)std::swap(n,m);
		fio<<((1ll*(n+1)*(m+1)%MOD*sum[n]%MOD-1ll*(n+m+2)*isum[n]+sqrisum[n])%MOD+MOD)%MOD<<'\n';
	}
	return fio.flush();
}