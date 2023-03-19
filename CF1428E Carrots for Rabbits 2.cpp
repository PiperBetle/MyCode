#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int sqr(int x){return x*x;}
inline int calc(int sum,int cnt){return (sum%cnt)*sqr(sum/cnt+1)+(cnt-sum%cnt)*sqr(sum/cnt);}
struct carrot{int sum,cnt;bool operator<(const carrot &n)const{return calc(sum,cnt)-calc(sum,cnt+1)<calc(n.sum,n.cnt)-calc(n.sum,n.cnt+1);}};
std::priority_queue<carrot>q;
int a[1000007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int ans=0;

	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i],q.push((carrot){a[i],1}),ans+=sqr(a[i]);
	for(i=1;i<=k-n;i++)
	{
		carrot ca=q.top();q.pop();
		ans-=calc(ca.sum,ca.cnt)-calc(ca.sum,ca.cnt+1);
		q.push((carrot){ca.sum,ca.cnt+1});
	}
	cout<<ans<<'\n';
	
	return 0;
}