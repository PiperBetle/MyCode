#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=5001;
int a[kN],p[kN],n,f[kN];
struct BIT{
	int data[kN]={};
	void clear(){memset(data+1,0,sizeof(int)*n);}
	void updata(int x,int k=1){for(;x<=n;x+=x&-x)data[x]+=k;}
	int query(int x){int k=0;for(;x;x-=x&-x)k+=data[x];return k;}
}b1,b2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],p[a[i]]=i;
	memset(f+1,0x3f,sizeof(int)*n);
	for(int i=1;i<=n;i++){
		b1.clear(),b2.updata(p[i]);
		for(int j=i,sum=0;j;j--)
			sum+=i-b1.query(p[j])-b2.query(p[j]),
			f[i]=std::min(f[i],f[j-1]+sum),
			b1.updata(p[j]);
	}
	cout<<f[n];
	return 0;
}