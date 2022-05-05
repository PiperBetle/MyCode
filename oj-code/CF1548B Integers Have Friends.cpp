#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>
using std::cin;using std::cout;
long long f[20][200007];
int n,lg[200007];
inline long long query(int l,int r){
	int t=lg[r-l+1];
	return std::__gcd(f[t][l],f[t][r-(1<<t)+1]);
}
signed main(){
//	freopen("ni.in","r",stdin);
//	freopen("ni.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	for(int i=2;i<200007;i++)lg[i]=lg[i>>1]+1;
	int T;cin>>T;while(T--){
		cin>>n;int ans=0;
		for(int i=1;i<=n;i++)cin>>f[0][i];
		for(int i=2;i<=n;i++)f[0][i-1]=llabs(f[0][i-1]-f[0][i]);
		for(int j=1;j<=lg[n];j++)for(int i=1;i+(1<<(j))-1<=n;i++)
            f[j][i]=std::gcd(f[j-1][i],f[j-1][i+(1<<(j-1))]);
		for(int i=1;i<n;i++){
			int l=i,r=n-1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(query(i,mid)!=1ll)l=mid+1,ans=std::max(ans,mid-i+1);
				else r=mid-1;
			}
		}
		cout<<ans+1<<'\n';
	}
	return 0;
}