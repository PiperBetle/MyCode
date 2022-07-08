#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_map>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int MOD=1e9+7,kN=1e4+1,kM=1e6+1;
inline int add0(int _x,int _y){return (_x+=_y)<MOD?_x:_x-MOD;}
template<typename...args>inline int add0(int _x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-MOD;}
inline int&add1(int&_x,int _y){return (_x+=_y)<MOD?_x:_x-=MOD;}
template<typename...args>inline int&add1(int&_x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-=MOD;}
inline int sub0(int _x,int _y){return (_x-=_y)<0?_x+MOD:_x;}
template<typename...args>inline int sub0(int _x,args..._y){return (_x-=add0(_y...))<0?_x+MOD:_x;}
inline int&sub1(int&_x,int _y){return (_x-=_y)<0?_x+=MOD:_x;}
template<typename...args>inline int&sub1(int&_x,args..._y){return (_x-=add0(_y...))<0?_x+=MOD:_x;}
inline int mul(int _x,int _y){return int(1ll*_x*_y%MOD);}
template<typename...args>inline int mul(int _x,args..._y){return int(1ll*_x*mul(_y...)%MOD);}
inline int qp(int _x,int _y){int _t=1;for(;_y;_y>>=1,_x=mul(_x,_x))if(_y&1)_t=mul(_x,_t);return _t;}
int n,a[kN],mip[kM],lcm=1,ans;
bool pr[kM];
std::unordered_map<int,int>mp;
std::basic_string<int>pt;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=2;i<kM;i++){
		if(!pr[i])pt+=i,mip[i]=i;
		for(int j:pt){
			if(i*j>=kM)break;
			pr[i*j]=true;
			mip[i*j]=j;
			if(i%j==0)break;
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		std::unordered_map<int,int>sum;
		for(int j=a[i];j!=1;j/=mip[j])sum[mip[j]]++;
		for(auto[x,y]:sum)mp[x]=std::max(mp[x],y);
	}
	for(auto[x,y]:mp)lcm=mul(lcm,qp(x,y));
	for(int i=1;i<=n;i++)add1(ans,mul(lcm,qp(a[i],MOD-2)));
	cout<<ans;
	return 0;
}