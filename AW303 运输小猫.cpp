#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1){t=-t;}return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
constexpr int kN=1e5+7,kM=1e2+7;
long long d[kN],sum[kN],f[kM][kN];
int q[kN],l,r;
struct cat{int h,t;long long s;friend bool operator<(const cat &x,const cat &y){return x.s<y.s;}}a[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m,p;fio>>n>>m>>p;
	for(int i=2;i<=n;i++)fio>>d[i],d[i]+=d[i-1];
	for(int i=1;i<=m;i++)fio>>a[i].h>>a[i].t,a[i].s=a[i].t-d[a[i].h];
	std::sort(a+1,a+1+m);
	for(int i=1;i<=m;i++)sum[i]=sum[i-1]+a[i].s;
	memset(f,0x3f,sizeof f);f[0][0]=0;
	for(int i=1;i<=p;i++){
		q[l=r=1]=0;
		for(int j=1;j<=m;j++){
			while(l<r&&f[i-1][q[l]]+sum[q[l]]-a[j].s*q[l]>f[i-1][q[l+1]]+sum[q[l+1]]-a[j].s*q[l+1])l++;
			f[i][j]=f[i-1][q[l]]+a[j].s*(j-q[l])-(sum[j]-sum[q[l]]);
			while(l<r&&(f[i-1][j]+sum[j]-f[i-1][q[r]]-sum[q[r]])*(q[r]-q[r-1])<(f[i-1][q[r]]+sum[q[r]]-f[i-1][q[r-1]]-sum[q[r-1]])*(j-q[r]))r--;
			q[++r]=j;
		}
	}
	fio<<f[p][m];
	return fio.flush();
}