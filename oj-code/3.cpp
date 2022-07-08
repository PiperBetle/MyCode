#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

vector<pair<int, int>> a;
int f[1 << 8], vis[8];
int main()
{
	int n;
	scanf("%d%*d%*d", &n);
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		a.push_back({l, i});
		a.push_back({r + 1, -i});
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < 256; i++)
		f[i] = -INF;
	for (int u = 0; u < a.size(); u++)
	{
		int id = a[u].second, k;
		int len = u == a.size() - 1 ? 0 : a[u + 1].first - a[u].first;
		if (id > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				if (vis[i] == 0)
				{
					vis[k = i] = id;
					break;
				}
			}
			for (int i = 255; i >= 0; i--)
			{
				if (i >> k & 1)
				{
					f[i] = f[i ^ 1 << k] + len * __builtin_parity(i);
				}
				else
				{
					f[i] = f[i] + len * __builtin_parity(i);
				}
			}
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				if (vis[i] == -id)
				{
					vis[k = i] = 0;
					break;
				}
			}
			for (int i = 0; i < 256; i++)
			{
				if (i >> k & 1)
				{
					f[i] = -INF;
				}
				else
				{
					f[i] = max(f[i], f[i ^ 1 << k]) + len * __builtin_parity(i);
				}
			}
		}
		for (int i = 0; i < 10; ++i)
			printf("%d ", f[i]);
		printf("\n");
	}
	printf("%d\n", f[0]);
	return 0;
}