#include<iostream>
#include<cstdio>
#include<algorithm>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,stnum[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)stnum[len++]=t%10+48,t/=10;while(len--)put(stnum[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)stnum[len++]=t%10+48,t/=10;while(len--)put(stnum[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)stnum[len++]=t%10+48,t/=10;while(len--)put(stnum[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)stnum[len++]=t%10+48,t/=10;while(len--)put(stnum[len]);return*this;}}fio;
int cnt[5],f[41][41][41][41],num[351];
inline void chkmax(int &x,const int &y){if(y>x)x=y;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m;fio>>n>>m;
	for(int i=1;i<=n;i++)fio>>num[i];
	f[0][0][0][0]=num[1];
	for(int i=1,t;i<=m;i++)fio>>t,cnt[t]++;
	for(int a=0;a<=cnt[1];a++)for(int b=0;b<=cnt[2];b++)for(int c=0;c<=cnt[3];c++)for(int d=0;d<=cnt[4];d++){
		int now=1+a+b*2+c*3+d*4;
		if(a)chkmax(f[a][b][c][d],f[a-1][b][c][d]+num[now]);
		if(b)chkmax(f[a][b][c][d],f[a][b-1][c][d]+num[now]);
		if(c)chkmax(f[a][b][c][d],f[a][b][c-1][d]+num[now]);
		if(d)chkmax(f[a][b][c][d],f[a][b][c][d-1]+num[now]);
	}
	fio<<f[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
	return fio.flush();
}