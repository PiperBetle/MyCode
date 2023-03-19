#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
#define double long double
using std::cin;using std::cout;
using std::pair;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int a[100007],b[100007],p[100007];
std::priority_queue<pair<int,int>,std::vector<pair<int,int> >,std::greater<pair<int,int> > > q;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;

	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>b[i];
	for(i=1;i<=n;i++)
		q.push(pair<int,int>(a[i]+b[++p[i]],i));
	T=n;
	while(T--)
	{
		pair<int,int> num=q.top();
		q.pop();
		cout<<num.first<<' ';
		q.push(pair<int,int>(a[num.second]+b[++p[num.second]],num.second));
	}
	cout<<'\n';
	
	return 0;
}