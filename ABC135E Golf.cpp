#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
int n=2,k,x,y;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>k>>x>>y;
	int opx=x/abs(x),opy=y/abs(y);x*=opx,y*=opy;
	if(x+y==k)return cout<<"1\n"<<x*opx<<' '<<y*opy,0;
	if(k%2==0&&(x+y)%2==1)return cout<<"-1",0;
	for(;n*k<x+y||(n*k-x-y)%2;)n++;
	cout<<n<<'\n';
	int b=(n*k-x-y)/2;
	for(int nx=0,ny=0;n--;cout<<nx*opx<<' '<<ny*opy<<'\n')
		if(b){
			if(b>=k){if(x-nx<y-ny)nx-=k;else ny-=k;b-=k;}
			else{if(x-nx<y-ny)nx-=b,ny+=k-b;else ny-=b,nx+=k-b;b=0;}
		}else{
			if(nx<x){if(x-nx>=k)nx+=k;else ny+=k-x+nx,nx=x;}
			else ny+=k;
		}
	return 0;
}