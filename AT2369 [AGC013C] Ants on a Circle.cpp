#include<iostream>
#include<cstdio>
#include<algorithm>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
const int kN=1e5+7;
int n,L,T,c[kN],id;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n>>L>>T;
	for(int i=0,x,w;i<n;i++){
		fio>>x>>w;if(w==1)x+=T;else x-=T;
		if(x>0)id=(id+x/L)%n;else id=((id+(x-L+1)/L)%n+n)%n;
		c[i]=(x%L+L)%L;
	}
	std::sort(c,c+n);
	for(int i=0;i<n;i++)fio<<c[(i+id+n)%n]<<' ';
	return fio.flush();
}