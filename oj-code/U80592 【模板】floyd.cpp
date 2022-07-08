#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll inf = 0x3f3f3f3f;
const ll inf_ll = 1e18;
const ll mod = 998244354;

ll f[1001][1001] = {0};

int main()
{
	ll n = 0;
	ll m = 0;
	ll s = 0;
	ll i = 0;
	ll j = 0;
	ll k = 0;
	ll x = 0;
	ll y = 0;
	ll l = 0;
	ll sum = 0;

	cin >> n >> m;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i != j)
			{
				f[i][j] = inf;
			}
		}
	}

	for (i = 1; i <= m; i++)
	{
		cin >> x >> y >> l;

		f[x][y] = l;
		f[y][x] = l;
	}

	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		sum = 0;

		for (j = 1; j <= n; j++)
		{
			if (i != j)
			{
				sum += f[i][j];
				sum %= mod;
			}
		}

		cout << sum << endl;
	}

	return 0;
}