#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int long long
#define siz(x) (int)(x).size()
using std::cin;using std::cout;
int a,b,c,d;
int calc(int l,int r,int x){
	int n1=(l/x+1-(l%x==0))*x,n2=(r/x)*x;
	return (n2-n1)/x+1;
}
signed main(){
//	freopen("div.in","r",stdin);
//	freopen("div.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>a>>b>>c>>d;
	cout<<(b-a+1-calc(a,b,c)-calc(a,b,d)+calc(a,b,c/std::__gcd(c,d)*d));
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}