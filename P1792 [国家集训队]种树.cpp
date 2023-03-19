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
struct tree{int data,left,right,ID;bool operator<(const tree &n)const{return data<n.data;}}a[200007];
bool b[200007];
std::priority_queue<tree>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;
	
	cin>>n>>m;
	if((n>>1)<m){cout<<"Error!";return 0;}
	for(i=1;i<=n;i++)cin>>a[i].data,a[i].left=i-1,a[i].right=i+1,a[i].ID=i,q.push(a[i]);
	a[1].left=n;a[n].right=1;
	while(m--)
	{
		while(b[q.top().ID])q.pop();
		tree now=q.top();q.pop();ans+=now.data;
		b[a[now.ID].left]=b[a[now.ID].right]=1;
		a[now.ID].data=a[a[now.ID].left].data+a[a[now.ID].right].data-a[now.ID].data;
		tree t=now;t.data=a[now.ID].data;q.push(t);
		a[now.ID].left=a[a[now.ID].left].left;a[now.ID].right=a[a[now.ID].right].right;
		a[a[now.ID].left].right=a[a[now.ID].right].left=now.ID;
	}
	cout<<ans;

	return 0;
}
