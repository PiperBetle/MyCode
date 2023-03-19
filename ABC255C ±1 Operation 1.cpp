#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
#define int long long
#define siz(x) int((x).size())
using std::cin;using std::cout;
// struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int x,a,d,n;// 首项 公差 项数
	cin>>x>>a>>d>>n;
	if(d<0)a=a+d*(n-1),d=-d;
	int l=a,r=a+d*(n-1);
	if(x<=l)return cout<<l-x,0;
	if(x>=r)return cout<<x-r,0;
	cout<<std::min(d-(x-l)%d,(x-l)%d);
	return 0;
}