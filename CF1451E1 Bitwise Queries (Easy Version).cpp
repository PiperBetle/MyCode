#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
constexpr int kN=(1<<16)+7;
int xr[kN],n,cnt[kN];
using std::cin,std::cout,std::endl;
auto AND=[](int a,int b){cout<<"AND "<<(a)<<' '<<(b)<<endl;int t;cin>>t;return t;};
auto XOR=[](int a,int b){cout<<"XOR "<<(a)<<' '<<(b)<<endl;int t;cin>>t;return t;};
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;cnt[0]=1;
	for(int i=2;i<=n;i++)cnt[xr[i]=XOR(1,i)]++;
	if(int p=std::max_element(cnt,cnt+n)-cnt;cnt[p]!=1){
		std::basic_string<int>g;
		for(int i=2;i<=n;i++)if(xr[i]==p)g+=i;
		int ak=AND(g.size()==1?1:g.front(),g.back()),a1=ak^p;
		cout<<"! "<<a1;
		for(int i=2;i<=n;i++)cout<<' '<<(a1^xr[i]);
	}else{
		int xp=-1,yp=-1,tx=1,ty=n>>1;
		for(int i=2;i<=n;i++){
			if(xr[i]==tx)xp=i;
			if(xr[i]==ty)yp=i;
		}
		int a1=AND(1,xp)|AND(1,yp);
		cout<<"! "<<a1;
		for(int i=2;i<=n;i++)cout<<' '<<(a1^xr[i]);
	}
	cout.flush();
	return 0;
}