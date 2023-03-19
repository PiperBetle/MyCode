#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[70];int get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++;}void put(const char&x){p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x));}public:int flush(){fwrite(obuf,p3-obuf,1,stdout);return 0;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(int c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(int c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;int c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;int c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c^48);return*this;}fastIO&operator<<(const char&t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char&it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}}fio;
constexpr int kN=1e5+7,kM=std::__lg(kN)+1;
int h[kN],next[2][kN],f[2][kN][kM],n,m;
long long dis[2][2][kN][kM+1];
using pii=std::pair<int,int>;
using pll=std::pair<long long,long long>;
std::vector<pii>np;
std::set<pii>s;
pll solve(int now,int lim){
	pll ans={0,0};
	for(int k=m;k>=0;k--)if(f[0][now][k]&&ans.first+ans.second+dis[0][0][now][k]+dis[0][1][now][k]<=lim)
		ans.first+=dis[0][0][now][k],ans.second+=dis[0][1][now][k],now=f[0][now][k];
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	fio>>n;m=std::__lg(n);
	for(int i=1;i<=n;i++)fio>>h[i];
	for(int i=n;i;i--){
		np.clear();auto it_l=s.lower_bound({h[i],i}),it_r=it_l;
		for(int j=0;j<2;j++)if(it_l!=s.begin())it_l--,np.emplace_back(h[i]-it_l->first,it_l->second);
		for(int j=0;j<2;j++)if(it_r!=s.end())np.emplace_back(it_r->first-h[i],it_r->second),it_r++;
		std::sort(np.begin(),np.end(),[](const pii &x,const pii &y){return x.first==y.first?h[x.second]<h[y.second]:x.first<y.first;});
		if(np.size()>1)next[0][i]=np[1].second;
		if(np.size()>0)next[1][i]=np[0].second;
		s.emplace(h[i],i);
	}
	for(int i=1;i<=n;i++){
		f[0][i][0]=next[0][i],f[1][i][0]=next[1][i];
		if(next[0][i])dis[0][0][i][0]=abs(h[next[0][i]]-h[i]);
		if(next[1][i])dis[1][1][i][0]=abs(h[next[1][i]]-h[i]);
	}
	for(int k=1;k<=m;k++)for(int i=1;i<=n;i++)
		if(k==1)f[0][i][k]=f[1][f[0][i][k-1]][k-1],f[1][i][k]=f[0][f[1][i][k-1]][k-1];
		else f[0][i][k]=f[0][f[0][i][k-1]][k-1],f[1][i][k]=f[1][f[1][i][k-1]][k-1];
	for(int k=1;k<=m;k++)for(int i=1;i<=n;i++)
		if(k==1)
			dis[0][0][i][k]=dis[0][0][i][k-1]+dis[1][0][f[0][i][k-1]][k-1],
			dis[0][1][i][k]=dis[0][1][i][k-1]+dis[1][1][f[0][i][k-1]][k-1],
			dis[1][0][i][k]=dis[1][0][i][k-1]+dis[0][0][f[1][i][k-1]][k-1],
			dis[1][1][i][k]=dis[1][1][i][k-1]+dis[0][1][f[1][i][k-1]][k-1];
		else
			dis[0][0][i][k]=dis[0][0][i][k-1]+dis[0][0][f[0][i][k-1]][k-1],
			dis[0][1][i][k]=dis[0][1][i][k-1]+dis[0][1][f[0][i][k-1]][k-1],
			dis[1][0][i][k]=dis[1][0][i][k-1]+dis[1][0][f[1][i][k-1]][k-1],
			dis[1][1][i][k]=dis[1][1][i][k-1]+dis[1][1][f[1][i][k-1]][k-1];
	int ans=0,stt,lim;double b=1e100;
	fio>>lim;for(int i=1;i<=n;i++){
		pll t=solve(i,lim);
		double c=t.second?1.*t.first/t.second:1e100;
		if(c<b||(c==b&&h[i]>h[ans]))b=c,ans=i;
	}
	fio<<ans<<'\n';int q;fio>>q;while(q--){
		fio>>stt>>lim;
		pll t=solve(stt,lim);
		fio<<t.first<<' '<<t.second<<'\n';
	}
	return fio.flush();
}