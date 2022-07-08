#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define siz(x) (int)(x).size()
using std::cin;using std::cout;
constexpr int kN=2e7+1;
inline auto get_z(const std::string &a){
	std::basic_string<int>z(siz(a),0);
	z[0]=siz(a);
	for(int i=1,l=-1,r=-1;i<siz(a);i++){
		if(i<=r)z[i]=std::min(z[i-l],r-i+1);
		while(z[i]+i<siz(a)&&a[z[i]+i]==a[z[i]])z[i]++;
		if(z[i]+i-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}
inline auto exkmp(const std::string &a,std::string &b){
	std::basic_string<int>z=get_z(b),p(siz(a),0);
	for(int i=0,l=-1,r=-1;i<siz(a);i++){
		if(i<=r)p[i]=std::min(z[i-l],r-i+1);
		while(p[i]+i<siz(a)&&a[p[i]+i]==b[p[i]])p[i]++;
		if(p[i]+i-1>r)l=i,r=i+p[i]-1;
	}
	return std::make_pair(z,p);
}
std::string a,b;
long long ans1,ans2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	a.reserve(kN),b.reserve(kN+1);
	cin>>a>>b;
	auto[z,p]=exkmp(a,b);
	for(int i=0;i<siz(z);i++)ans1^=1ll*(i+1)*(z[i]+1);
	for(int i=0;i<siz(p);i++)ans2^=1ll*(i+1)*(p[i]+1);
	cout<<ans1<<'\n'<<ans2;
//	std::cerr<<clock();
	return 0;
}