#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct ball{int ID,cnt;bool operator<(const ball &n)const{return cnt<n.cnt;}}a,b;
std::priority_queue<ball>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;

	cin>>n>>m;
	for(i=1;i<=m;i++){cin>>a.cnt;if(!a.cnt)continue;a.ID=i;q.push(a);}
	while(!q.empty())
	{
		a=q.top();q.pop();
		b=q.top();q.pop();
		a.cnt--;b.cnt--;
		cout<<a.ID<<' '<<b.ID<<'\n';
		if(a.cnt>0)q.push(a);
		if(b.cnt>0)q.push(b);
	}

	return 0;
}