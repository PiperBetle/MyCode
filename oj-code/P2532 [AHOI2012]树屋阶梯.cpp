#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using std::cin;using std::cout;
struct bigint{
	std::vector<int>num;
	bigint &operator=(std::string s){
		reverse(s.begin(),s.end());
		num.resize(s.size());
		for(size_t i=0;i<num.size();i++)num[i]=s[i]-48;
		return *this;
	}
	bigint &operator=(const int &t){return *this=std::to_string(t);}
	bigint(){num.clear();}
	bigint(const int &t){*this=std::to_string(t);}
	bigint del0(){while(!(num.empty()||num.back()))num.pop_back();return *this;}
	void read(){std::string s;cin>>s;*this=s;}
	void write(){for(int i=num.size()-1;i>=0;i--)cout<<num[i];cout<<'\n';}
	friend bigint operator+(const bigint &x,const bigint &y){
		bigint res;res.num.resize(std::max(x.num.size(),y.num.size())+1);
		for(size_t i=0;i<x.num.size();i++)res.num[i]+=x.num[i];
		for(size_t i=0;i<y.num.size();i++)res.num[i]+=y.num[i];
		for(size_t i=0;i<res.num.size();i++)if(res.num[i]>9)res.num[i]-=10,res.num[i+1]++;
		return res.del0();
	}
	friend bigint operator-(const bigint &x,const bigint &y){
		bigint res;res.num.resize(std::max(x.num.size(),y.num.size()));
		for(size_t i=0;i<x.num.size();i++)res.num[i]+=x.num[i];
		for(size_t i=0;i<y.num.size();i++)res.num[i]-=y.num[i];
		for(size_t i=0;i<res.num.size();i++)if(res.num[i]<0)res.num[i]+=10,res.num[i+1]--;
		return res.del0();
	}
	friend bigint operator*(const bigint &x,const bigint &y){
		bigint res;res.num.resize(x.num.size()+y.num.size()+2);
		for(size_t i=0;i<x.num.size();i++)for(size_t j=0;j<y.num.size();j++)res.num[i+j]+=x.num[i]*y.num[j];
		for(size_t i=0;i<res.num.size();i++)if(res.num[i]>9)res.num[i+1]+=res.num[i]/10,res.num[i]%=10;
		return res.del0();
	}
	friend bigint operator*(const bigint &x,const int &y){
		bigint res;res.num.resize(x.num.size()+10);
		for(size_t i=0;i<x.num.size();i++)res.num[i]=x.num[i]*y;
		for(size_t i=0;i<res.num.size();i++)if(res.num[i]>9)res.num[i+1]+=res.num[i]/10,res.num[i]%=10;
		return res.del0();
	}
	friend bigint operator/(const bigint &x,const int &y){
		bigint res;int sum=0;res.num.resize(x.num.size());
		for(int i=x.num.size()-1;i>=0;i--)sum=sum*10+x.num[i],res.num[i]=sum/y,sum%=y;
		return res.del0();
	}
	int operator%(const int &n){
		int res=0;
		for(int i=num.size()-1;i>=0;i--)res=(res+num[i])%n;
		return res;
	}
	bigint operator+=(const auto &t){return *this=std::move(*this+t);}
	bigint operator-=(const auto &t){return *this=std::move(*this-t);}
	bigint operator*=(const auto &t){return *this=std::move(*this*t);}
	bigint operator/=(const auto &t){return *this=std::move(*this/t);}
	friend bool operator<(const bigint &x,const bigint &y){
		if(x.num.size()!=y.num.size())return x.num.size()<y.num.size();
		for(int i=x.num.size()-1;i>=0;i--)if(x.num[i]!=y.num[i])return x.num[i]<y.num[i];
		return 0;
	}
	friend bool operator==(const bigint &x,const bigint &y){
		if(x.num.size()!=y.num.size())return 0;
		for(int i=x.num.size()-1;i>=0;i--)if(x.num[i]!=y.num[i])return 0;
		return 1;
	}
}ans=1;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n;cin>>n;
	for(int i=n+2;i<=n*2;i++)ans*=i;
	for(int i=1;i<=n;i++)ans/=i;
	ans.write();
	return 0;
}