#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
constexpr int kN=1e6+7;
int t[kN],c[kN],f[kN],q[kN],l,r;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,s;cin>>n>>s;
	for(int i=1;i<=n;i++)cin>>t[i]>>c[i],t[i]+=t[i-1],c[i]+=c[i-1];
	q[l=r=1]=0;f[0]=0;std::fill_n(f+1,n,0x3f3f3f3f);
	for(int i=1;i<=n;i++){
		while(l<r&&f[q[l+1]]-f[q[l]]<=(s+t[i])*(c[q[l+1]]-c[q[l]]))l++;
		f[i]=f[q[l]]+t[i]*c[i]+s*c[n]-c[q[l]]*(s+t[i]);
		while(l<r&&(f[i]-f[q[r]])*(c[q[r]]-c[q[r-1]])<=(f[q[r]]-f[q[r-1]])*(c[i]-c[q[r]]))r--;
		q[++r]=i;
	}
	cout<<f[n];
	return 0;
}