#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
struct grass{int col1,val,col2;}a[107];
int n,f[107][107][5][5];
signed main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k,ans=-0x3f3f3f3f3f3f3f3f;
	cin>>n;
	memset(f,-0x3f,sizeof f);
	for(i=1;i<=n;i++)
		cin>>a[i].col1>>a[i].val>>a[i].col2,
		f[i][i][a[i].col1][a[i].col2]=a[i].val,
		f[i][i][a[i].col2][a[i].col1]=a[i].val,
		ans=std::max(ans,a[i].val);
	for(j=1;j<=n;j++)for(i=j-1;i>=1;i--)for(int c1=1;c1<=4;c1++)for(int c2=1;c2<=4;c2++){
		for(k=i;k<j;k++){
			f[i][j][c1][c2]=std::max({f[i][j][c1][c2],f[i][k][c1][c2],f[k+1][j][c1][c2]});
			for(int c3=1;c3<=4;c3++)	
				f[i][j][c1][c2]=std::max({f[i][j][c1][c2],f[i][k][c3][c2]+f[k+1][j][c1][c3],f[i][k][c1][c3]+f[k+1][j][c3][c2]});
			ans=std::max(ans,f[i][j][c1][c2]);
		}
	}
	cout<<ans;
	return 0;
}