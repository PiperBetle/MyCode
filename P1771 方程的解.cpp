#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
struct bigint:std::basic_string<int>{
#define num (*this)
	bigint &operator=(std::string s){
		reverse(s.begin(),s.end());
		num.resize(s.size());
		for(int i=0;i<siz(num);i++)num[i]=s[i]-48;
		return num;
	}
	bigint &operator=(const int &t){return num=std::to_string(t);}
	bigint()=default;
	bigint(cauto &t){num=std::to_string(t);}
	bigint &del0(){while(!num.empty()&&!num.back())num.pop_back();return num;}
	bigint &upbit(){for(int i=0;i<siz(num)-1;i++)num[i+1]+=num[i]/10,num[i]%=10;return del0();}
	template<typename any>friend any &operator<<(any &x,const bigint &y){for(int i=siz(y)-1;i>=0;i--)x<<y[i];return x;}
	friend bigint operator+(const bigint &x,const bigint &y){
		bigint z;z.resize(std::max(siz(x),siz(y))+1);
		for(int i=0;i<siz(x);i++)z[i]+=x[i];
		for(int i=0;i<siz(y);i++)z[i]+=y[i];
		return z.upbit();
	}
	friend bigint operator-(const bigint &x,const bigint &y){
		bigint z;z.resize(std::max(siz(x),siz(y)));
		for(int i=0;i<siz(x);i++)z[i]+=x[i];
		for(int i=0;i<siz(y);i++)z[i]-=y[i];
		for(int i=0;i<siz(z);i++)if(z[i]<0)z[i]+=10,z[i+1]--;
		return z.del0();
	}
	friend bigint operator*(const bigint &x,const bigint &y){
		bigint z;z.resize(siz(x)+siz(y)+2);
		for(int i=0;i<siz(x);i++)for(int j=0;j<siz(y);j++)z[i+j]+=x[i]*y[j];
		return z.upbit();
	}
	friend bigint operator*(const bigint &x,const int &y){
		bigint z;z.resize(siz(x)+10);
		for(int i=0;i<siz(x);i++)z[i]=x[i]*y;
		return z.upbit();
	}
	bigint &operator*=(const int &t){
		num.resize(siz(num)+10);
		for(int i=0;i<siz(num);i++)num[i]*=t;
		return upbit();
	}
	friend bigint operator/(const bigint &x,const int &y){
		bigint z;int sum=0;z.resize(siz(x));
		for(int i=siz(x)-1;i>=0;i--)sum=sum*10+x[i],z[i]=sum/y,sum%=y;
		return z.del0();
	}
	bigint &operator/=(const int &t){
		int sum=0;
		for(int i=siz(num)-1;i>=0;i--)sum=sum*10+num[i],num[i]=sum/t,sum%=t;
		return del0();
	}
	friend bigint operator%(const bigint &x,const int &y){
		int z=0;
		for(int i=siz(x)-1;i>=0;i--)z=(z+x[i])%y;
		return z;
	}
	friend bool operator<(const bigint &x,const bigint &y){
		if(siz(x)!=siz(y))return siz(x)<siz(y);
		for(int i=siz(x)-1;i>=0;i--)if(x[i]!=y[i])return x[i]<y[i];
		return 0;
	}
	friend bool operator==(const bigint &x,const bigint &y){
		if(siz(x)!=siz(y))return 0;
		for(int i=siz(x)-1;i>=0;i--)if(x[i]!=y[i])return 0;
		return 1;
	}
#undef num
};
int n,k;
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%1000)if(b&1)t=t*a%1000;return t;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	k=qp(k%1000,k);
	if(k--<n--)return cout<<0,0;
	bigint c=1;
	for(int i=2;i<=k;i++)c*=i;
	for(int i=2;i<=n;i++)c/=i;
	for(int i=2;i<=k-n;i++)c/=i;
	cout<<c;
	return 0;
}