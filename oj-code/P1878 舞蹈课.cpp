#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct people{int x,y,delta;bool operator<(const people &n)const{if(delta==n.delta)return x>n.x;return delta>n.delta;}}ans[1000007];
struct person{char sex;int data;bool used;person(){used=0;}}a[1000007];
std::priority_queue<people,std::vector<people> >q;
std::string s;
int cnt=0;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;

	cin>>n>>s;
	for(i=0;i<n;cin>>a[++i].data,a[i].sex=s[i-1]);
	for(i=1;i<n;i++)if(a[i].sex!=a[i+1].sex)q.push((people){i,i+1,abs(a[i].data-a[i+1].data)});
	while(!q.empty())
	{
		int nx=q.top().x,ny=q.top().y;q.pop();
		if(a[nx].used||a[ny].used)continue;
		a[nx].used=a[ny].used=1;
		ans[++cnt].x=nx;ans[cnt].y=ny;
		while(nx>=1&&a[nx].used)nx--;
		while(ny<=n&&a[ny].used)ny++;
		if(nx>=1&&ny<=n&&a[nx].sex!=a[ny].sex)q.push((people){nx,ny,abs(a[nx].data-a[ny].data)});
	}
	cout<<cnt<<'\n';
	for(i=1;i<=cnt;cout<<ans[i].x<<' '<<ans[i++].y<<'\n');
	
	return 0;
}