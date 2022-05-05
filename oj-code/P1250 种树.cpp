#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct tree{int l,r,cnt;bool operator<(const tree &n)const{return r<n.r;}}a[100007];
bool b[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;

	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>a[i].l>>a[i].r>>a[i].cnt;
	std::sort(a+1,a+1+m);
	for(i=1;i<=m;i++)
	{
		int sum=a[i].cnt;
		for(j=a[i].l;j<=a[i].r;j++)sum-=b[j];
		if(sum<=0)continue;
		for(j=a[i].r;j>=a[i].l;j--)if(!b[j])if((sum-=b[j]=1)==0)break;
	}
	for(i=1;i<=n;i++)ans+=b[i];
	cout<<ans;

	return 0;
}