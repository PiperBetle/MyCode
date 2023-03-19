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
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2750132;
bool pr[N];
int n,mif[N],rk[N],b[N];
std::basic_string<int>pt;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	mif[1]=pr[1]=true;
	for(int i=2;i<N;i++){
		if(!pr[i])pt+=i,mif[i]=i;
		for(int j:pt){
			if(i*j>=N)break;
			pr[i*j]=true;
			mif[i*j]=j;
			if(i%j==0)break;
		}
	}
	for(int i=0;i<siz(pt);i++)rk[pt[i]]=i+1;
	cin>>n;
	for(int i=1,x;i<=n*2;i++)cin>>x,b[x]++;
	for(int i=N-1;i>=1;i--)while(b[i]--){
		if(!pr[i])b[rk[i]]--,cout<<rk[i]<<' ';
		else b[i/mif[i]]--,cout<<i<<' ';
	}
	return 0;
}