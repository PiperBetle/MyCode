#include<iostream>
#include<cmath>
using std::cin;using std::cout;
template<typename any>inline any min(any x,any y){return x<y?x:y;}
int n,m,ans=0x3f3f3f3f;
int min_v[21],min_s[21];
void dfs(int depth,int sum_v,int sum_s,int r,int h){
	if(!depth){if(sum_v==n)ans=min(ans,sum_s);return;}
	if(sum_v+min_v[depth-1]>n||sum_s+min_s[depth-1]>ans)return;
	if(sum_s+((n-sum_v)<<1)/r>ans)return;
	for(int i=r-1;i>=depth;i--)for(int j=h-1;j>=depth;j--){
		if(depth==m)sum_s=i*i;
		dfs(depth-1,sum_v+i*i*j,sum_s+((i*j)<<1),i,j);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)min_v[i]=min_v[i-1]+i*i*i,min_s[i]=min_s[i-1]+((i*i)<<1);
	dfs(m,0,0,sqrt(n),n);
	cout<<(ans==0x3f3f3f3f?0:ans);
	return 0;
}