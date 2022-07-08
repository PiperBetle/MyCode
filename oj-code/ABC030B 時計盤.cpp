#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<iomanip>
#include<cmath>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
int a,b;
double x,y;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(6);
	cin>>a>>b;a%=12;
	x=30*a;y=6*b;x+=0.5*b;
	cout<<std::min(fabs(x-y),360-fabs(x-y));
	return 0;
}