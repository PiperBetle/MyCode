#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	double a,b,c,x;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&x);
	if(x<=a)printf("%.12lf",1.0);
	else if(a+1<=x&&x<=b)printf("%.12lf",c/(b-a));
	else printf("%.12lf",0.0);
	return 0;
}