#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
int T,n,sum[16],ans;
void dfs(int now){
	if(now>=ans)return;
	for(int d=3;d>=1;d--)for(int i=3,k=0;i<=14;i++){
		if(sum[i]<d){k=0;continue;}
		if(++k*d>=5){
			for(int j=i-k+1;j<=i;j++)sum[j]-=d;
			dfs(now+1);
			for(int j=i-k+1;j<=i;j++)sum[j]+=d;
		}
	}
	for(int i=2;i<=14;i++){
		if(sum[i]<3)continue;
		if(sum[i]>=3){
			sum[i]-=3;
			for(int d=2;d>=1;d--)for(int j=2;j<=16-d;j++)
				if(i!=j&&sum[j]>=d)sum[j]-=d,dfs(now+1),sum[j]+=d;
			sum[i]+=3;
		}
		if(sum[i]>=4){
			sum[i]-=4;
			for(int d=2;d>=1;d--)for(int j1=2;j1<=16-d;j1++)if(i!=j1&&sum[j1]>=d)
				for(int j2=2;j2<=16-d;j2++)if(i!=j2&&j1!=j2&&sum[j2]>=d)
					sum[j1]-=d,sum[j2]-=d,dfs(now+1),sum[j1]+=d,sum[j2]+=d;
			sum[i]+=4;
		}
	}
	for(int i=2;i<=15;i++)if(sum[i])now++;
	ans=std::min(ans,now);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>T>>n;while(T--){
		memset(sum,0,sizeof sum);
		ans=0x3f3f3f3f;
		for(int i=1,x;i<=n;cin>>x,i++)switch(cin>>x;x){
			case 0:sum[15]++;break;
			case 1:sum[14]++;break;
			default:sum[x]++;break;
		}
		dfs(0);
		cout<<ans<<'\n';
	}
	return 0;
}