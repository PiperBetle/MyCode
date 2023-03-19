#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
struct bigint:std::basic_string<int>{
#define num (*this)
	bigint &operator=(std::string s){
		reverse(all(s));
		for(int i=0;i<siz(num);i++)num[i]=s[i]-48;
		return num;
	}
	bigint &operator=(const int &t){return num=std::to_string(t);}
	bigint()=default;
	bigint(const int t){num=std::to_string(t);}
	bigint &del0(){while(!empty()&&!back())pop_back();return num;}
	template<typename any>friend any &operator>>(any &x,bigint &y){std::string s;x>>s;y=s;return x;}
	template<typename any>friend any &operator<<(any &x,const bigint &y){for(int i=siz(y)-1;i>=0;i--)cout<<y[i];cout<<'\n';return x;}
	friend bigint operator+(const bigint &x,const bigint &y){
		bigint res;res.resize(std::max(siz(x),siz(y))+1);
		for(int i=0;i<siz(x);i++)res[i]+=x[i];
		for(int i=0;i<siz(y);i++)res[i]+=y[i];
		for(int i=0;i<siz(res)-1;i++)if(res[i]>9)res[i]-=10,res[i+1]++;
		return res.del0();
	}
	friend bigint operator-(const bigint &x,const bigint &y){
		bigint res;res.resize(std::max(siz(x),siz(y)));
		for(int i=0;i<siz(x);i++)res[i]+=x[i];
		for(int i=0;i<siz(y);i++)res[i]-=y[i];
		for(int i=0;i<siz(res)-1;i++)if(res[i]<0)res[i]+=10,res[i+1]--;
		return res.del0();
	}
	friend bigint operator*(const bigint &x,const bigint &y){
		bigint res;res.resize(siz(x)+siz(y)+2);
		for(int i=0;i<siz(x);i++)for(int j=0;j<siz(y);j++)res[i+j]+=x[i]*y[j];
		for(int i=0;i<siz(res)-1;i++)if(res[i]>9)res[i+1]+=res[i]/10,res[i]%=10;
		return res.del0();
	}
	friend bigint operator*(const bigint &x,const int y){
		bigint res;res.resize(siz(x)+10);
		for(int i=0;i<siz(x);i++)res[i]=x[i]*y;
		for(int i=0;i<siz(res)-1;i++)if(res[i]>9)res[i+1]+=res[i]/10,res[i]%=10;
		return res.del0();
	}
	friend bigint operator/(const bigint &x,const int y){
		bigint res;int sum=0;res.resize(siz(x));
		for(int i=siz(x)-1;i>=0;i--)sum=sum*10+x[i],res[i]=sum/y,sum%=y;
		return res.del0();
	}
	friend int operator%(const bigint &x,const int y){
		int res=0;
		for(int i=siz(x)-1;i>=0;i--)res=(res+x[i])%y;
		return res;
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
	friend bool operator!=(const bigint &x,const bigint &y){
		if(siz(x)!=siz(y))return 1;
		for(int i=siz(x)-1;i>=0;i--)if(x[i]!=y[i])return 0;
		return 0;
	}
#undef num
};
bigint n,l,r;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;l=1,r=0;
		for(;n!=0;n=n/2){
			if(n%2)l=l+r;
			else r=l+r;
		}
		cout<<r<<'\n';
	}
	return 0;
}