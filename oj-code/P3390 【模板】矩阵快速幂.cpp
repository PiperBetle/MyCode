#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?(file_end=true),EOF:*p1++;}void put(char x){p3-obuf<1000007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();isspace(t);t=get());return*this;}fastIO&operator>>(char*t){for(char c=get();c!=10;c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();for(char c=get();!isspace(c);c=get())t.push_back(c);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c-48);if(y==1)t=-t;return*this;}fastIO&operator>>(__int128_t&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=t*10+(c-48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c-48);return*this;}fastIO&operator>>(__uint128_t&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=t*10+(c-48);return*this;}template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}fastIO&operator<<(const char t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<std::is_signed<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__int128_t t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<std::is_unsigned<any>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}fastIO&operator<<(__uint128_t t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
#define int __int128_t
constexpr int MOD=1e9+7;
struct matrix{
	int data[101][101],size;
	matrix(){}
	matrix(int x):size(x){for(int i=1;i<=size;i++)memset(data[i]+1,0,sizeof(int)*size);}
	void build(){for(int i=1;i<=size;i++)data[i][i]=1;}
	int *operator[](int t){return data[t];}
	const int *operator[](int t)const{return data[t];}
	matrix operator*(const matrix &t){
		matrix res(size);
		for(int k=1;k<=size;k++)for(int i=1;i<=size;i++)for(int j=1;j<=size;j++)
			res[i][j]+=data[i][k]*t[k][j];
		for(int i=1;i<=size;i++)for(int j=1;j<=size;j++)res[i][j]%=MOD;
		return res;
	}
	matrix operator*=(const matrix &t){
		matrix res(size);
		for(int k=1;k<=size;k++)for(int i=1;i<=size;i++)for(int j=1;j<=size;j++)
			res[i][j]+=data[i][k]*t[k][j];
		for(int i=1;i<=size;i++)for(int j=1;j<=size;j++)res[i][j]%=MOD;
		return *this=std::move(res);
	}
	matrix &operator^=(int t){
		matrix res(size);res.build();
		for(;t;t>>=1,*this*=*this)if(t&1)res*=*this;
		return *this=std::move(res);
	}
};
matrix a;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int m;fio>>a.size>>m;
	for(int i=1;i<=a.size;i++)for(int j=1;j<=a.size;j++)fio>>a[i][j];
	a^=m;
	for(int i=1;i<=a.size;i++,fio<<'\n')for(int j=1;j<=a.size;j++)fio<<a[i][j]<<' ';
	return 0;
}