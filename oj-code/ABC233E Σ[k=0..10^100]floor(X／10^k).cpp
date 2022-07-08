#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
struct bigint{
	std::basic_string<int>data;
	bigint &operator=(const std::string &t){
		data.resize(t.size());
		for(size_t i=0;i<data.size();i++)data[i]=t[i]-48;
		std::reverse(data.begin(),data.end());
		return *this;
	}
	bigint &operator=(const int &t){return *this=std::to_string(t);}
	bigint(){data.clear();}
	bigint(const int &t){*this=std::to_string(t);}
	template<typename any>friend any &operator>>(any &x,bigint &y){std::string s;x>>s;y=s;return x;}
	template<typename any>friend any &operator<<(any &x,const bigint &y){for(size_t i=y.data.size()-1;~i;i--)x<<y.data[i];return x;}
	bigint(const std::string &t){*this=t;}
	bigint &upbit(){for(size_t i=0;i<data.size();i++)if(data[i]>9)data[i+1]+=data[i]/10,data[i]%=10;return this->del0();}
	bigint &del0(){while(!data.empty()&&!data.back())data.pop_back();if(data.empty())data+=0;return *this;}
	friend bigint operator+(const bigint &x,const bigint &y){
		bigint z;z.data.resize(std::max(x.data.size(),y.data.size())+1);
		for(size_t i=0;i<x.data.size();i++)z.data[i]+=x.data[i];
		for(size_t i=0;i<y.data.size();i++)z.data[i]+=y.data[i];
		return z.upbit();
	}
	friend bigint &operator+=(bigint &x,const bigint &y){
		x.data.resize(std::max(x.data.size(),y.data.size())+1);
		for(size_t i=0;i<y.data.size();i++)x.data[i]+=y.data[i];
		return x.upbit();
	}
	friend bigint operator*(const bigint &x,const int &y){
		bigint z;z.data.resize(x.data.size()+10);
		for(size_t i=0;i<x.data.size();i++)z.data[i]=x.data[i]*y;
		return z.upbit();
	}
	friend bigint &operator*=(bigint &x,const int &y){
		x.data.resize(x.data.size()+10);
		for(size_t i=0;i<x.data.size();i++)x.data[i]*=y;
		return x.upbit();
	}
	friend bigint operator*(const bigint &x,const bigint &y){
		bigint z;z.data.resize(x.data.size()+y.data.size());
		for(size_t i=0;i<x.data.size();i++)for(size_t j=0;j<y.data.size();j++)z.data[i+j]+=x.data[i]*y.data[j];
		return z.upbit();
	}
	friend bigint &operator*=(bigint &x,const bigint &y){
		bigint z;z.data.resize(x.data.size()+y.data.size());
		for(size_t i=0;i<x.data.size();i++)for(size_t j=0;j<y.data.size();j++)z.data[i+j]+=x.data[i]*y.data[j];
		return x=z.upbit();
	}
	friend bigint operator%(const bigint &x,const int &y){
		int z=0;
		for(size_t i=x.data.size()-1;~i;i--)z=(z*10+x.data[i])%y;
		return z;
	}
};
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	return 0;
}