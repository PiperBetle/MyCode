#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
constexpr int kN=55555;
bool pr[kN];
std::basic_string<int>pt;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=2;i<kN;i++){
		if(!pr[i])pt+=i;
		for(int j:pt){
			if(i*j>=kN)break;else pr[i*j]=true;
			if(i%j==0)break;
		}
	}
	int n;cin>>n;
	for(int i:pt){
		if(i%10==7){
			cout<<i<<' ';
			if(!--n)return 0;
		}
	}
	return 0;
}