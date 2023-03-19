#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
std::string s;
int f[107][107],cnt[107];
void dfs(int now)
{
	for(int i='a';i<='z';i++)
	{
		if(f[now][i]<1)continue;
		f[now][i]--;f[i][now]--;
		dfs(i);
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>s;
			char begin=s[0],end=s[s.length()-1];
			a[begin][end]++;a[end][begin]++;
			cnt[begin]++;cnt[end]++;
		}
		int start;
		for(i=1;i<=n;i++)if(cnt[i]&1){start=i;break;}
		dfs(start);
	}

	return 0;
}
