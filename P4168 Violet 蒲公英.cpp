#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
int a[40007],bl[40007],f[207][207],s[207][40007],mp[40007],cnt[40007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k,n,m,l,r,x=0;fio>>n>>m;int sz=__builtin_sqrt(n),num=0;
	for(i=1;i<=n;i++){fio>>a[i];mp[i]=a[i];if(i%sz==1)num++;bl[i]=num;}
	std::sort(mp+1,mp+1+n);l=std::unique(mp+1,mp+n+1)-mp-1;
	for(i=1;i<=n;i++)a[i]=std::lower_bound(mp+1,mp+1+l,a[i])-mp;
	for(i=1;i<=num;i++)for(j=sz*(i-1)+1;j<=std::min(n,sz*i);j++)s[i][a[j]]++;
	for(i=1;i<=num;i++)for(j=1;j<=l;j++)s[i][j]+=s[i-1][j];
	#define compare(d1,n1,d2,n2) if((d1>d2)||(n1<n2&&d1==d2))n2=n1
	for(i=1;i<=num;i++)for(j=i;j<=num;j++)for(f[i][j]=f[i][j-1],k=sz*(j-1)+1;k<=std::min(n,sz*j);k++)
		compare(s[j][a[k]]-s[i-1][a[k]],a[k],s[j][f[i][j]]-s[i-1][f[i][j]],f[i][j]);
	while(m--){
		fio>>l>>r;l=(l+x-1)%n+1;r=(r+x-1)%n+1;if(l>r)std::swap(l,r);
		if(bl[r]-bl[l]<=1){
			for(x=0,i=l;i<=r;i++)cnt[a[i]]++;
			for(i=l;i<=r;i++)compare(cnt[a[i]],a[i],cnt[x],x);
			for(i=l;i<=r;i++)cnt[a[i]]=0;
			fio<<(x=mp[x])<<'\n';continue;
		}
		#define count(x) cnt[x]+s[bl[r]-1][x]-s[bl[l]][x]
		for(x=f[bl[l]+1][bl[r]-1],i=l;i<=sz*bl[l];i++)cnt[a[i]]++;
		for(i=sz*(bl[r]-1)+1;i<=r;i++)cnt[a[i]]++;
		for(i=l;i<=sz*bl[l];i++)compare(count(a[i]),a[i],count(x),x);
		for(i=sz*(bl[r]-1)+1;i<=r;i++)compare(count(a[i]),a[i],count(x),x);
		for(i=l;i<=sz*bl[l];i++)cnt[a[i]]=0;
		for(i=sz*(bl[r]-1)+1;i<=r;i++)cnt[a[i]]=0;
		fio<<(x=mp[x])<<'\n';
	}
	return fio.flush();
}