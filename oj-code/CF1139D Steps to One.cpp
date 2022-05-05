#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
std::vector<int>pt;
constexpr int MOD=1000000007;
bool pr[1500007];
int miu[1500007],inv[1500007];
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	for(int i=2;i<=150000;i++){
		if(!pr[i])pt.emplace_back(i),miu[i]=-1;
		for(int j:pt){
			if(i*j>150000)break;
			pr[i*j]=true;
			if(i%j==0){miu[i*j]=0;break;}
			miu[i*j]=miu[i]*miu[j];
		}
	}
	inv[1]=1;for(int i=2;i<=150000;i++)inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	int n,ans=1;cin>>n;
	for(int i=2;i<=n+1;i++)
		(ans+=MOD-miu[i]*(n/i)*inv[n-n/i]%MOD)%=MOD;
	cout<<ans;
	return 0;
}