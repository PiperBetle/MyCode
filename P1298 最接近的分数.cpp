#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<random>
#define double long double
using std::cin;using std::cout;
template<typename T>inline T abs(T x){return x>0?x:-x;}
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,t;
	double f;
	cin>>n>>m>>f;
	int fz=n,fm=1;
	for(i=1;i<=m;i++){
		t=1.0*f*i+0.5;
		if(t>n)break;
		if(abs(1.0*t/i-f)<abs(1.0*fz/fm-f)){
			fz=t;fm=i;
			int g=gcd(fz,fm);
			fz/=g;fm/=g;
		}
		if(abs(1.0*t/i-f)==abs(1.0*fz/fm-f)){
			int tfz=t,tfm=i;
			int g=gcd(tfz,tfm);
			tfz/=g;tfm/=g;
			if(tfz!=fz||tfm!=fm)return cout<<"TOO MANY",0;
		}
	}
	if(fz==0)if(std::random_device{}()&1)return cout<<"TOO MANY",0;
	cout<<fz<<'/'<<fm;
	return 0;
}