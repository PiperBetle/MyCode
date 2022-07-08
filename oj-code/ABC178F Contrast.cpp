#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
using lolo=long long;
using i128=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1;
int n,a[kN],b[kN],l=n+1,r=0,c=-1;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	std::reverse(b+1,b+1+n);
	for(int i=1;i<=n;i++)
		if(c==-1&&a[i]==b[i])l=i,r=i,c=a[i];
		else if(c!=-1&&a[i]==b[i])r=i;
	for(int i=1;i<=n;i++)
		if(c!=a[i]&&c!=b[i]&&l<=r)
			std::swap(b[i],b[l++]);
	if(l<=r)return cout<<"No",0;
	cout<<"Yes\n";
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	return 0;
}