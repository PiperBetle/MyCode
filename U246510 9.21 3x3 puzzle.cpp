#include <bits/stdc++.h>
using namespace std;
int q, ans[4][4], c[3][3], las = -1, s[3], h[3], a[7][3][3] = {2, 1, 3, 2, 1, 3, 2, 1, 3,

															   2, 1, 3, 3, 1, 2, 1, 2, 3,

															   2, 1, 3, 2, 1, 3, 2, 3, 1,

															   1, 2, 3, 2, 3, 1, 3, 1, 2,

															   2, 3, 1, 2, 3, 1, 2, 1, 3,

															   2, 3, 1, 3, 2, 1, 1, 3, 2,

															   2, 3, 1, 2, 3, 1, 2, 3, 1};
inline void dfs(int x, int y)
{
	if (y >= 3)
		++x, y = 0;
	if (x >= 3)
	{
		int sum[3] = {0, 0, 0};
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				++sum[ans[i][j] - 1];
		if (sum[0] != 3 || sum[1] != 3 || sum[2] != 3)
			return;
		if (ans[0][0] + ans[0][1] + ans[0][2] >= h[0] &&
			ans[1][0] + ans[1][1] + ans[1][2] >= h[1] &&
			ans[2][0] + ans[2][1] + ans[2][2] >= h[2] &&
			ans[0][0] + ans[1][0] + ans[2][0] >= s[0] &&
			ans[0][1] + ans[1][1] + ans[2][1] >= s[1] &&
			ans[0][2] + ans[1][2] + ans[2][2] >= s[2])
		{
			cout << ans[0][0] << ' ' << ans[1][0] << ' ' << ans[2][0] << ' ' << ans[0][1] << ' ' << ans[1][1] << ' ' << ans[2][1] << ' ' << ans[0][2] << ' ' << ans[1][2] << ' ' << ans[2][2] << std::endl;
			int x;
			cin >> x;
			if (x == 6)
				exit(0);
		}
		return;
	}
	for (int i = 1; i <= 3; ++i)
	{
		ans[x][y] = i;
		dfs(x, y + 1);
	}
}
int main()
{
	cin >> q;
	for (int i = 0; i < 2; ++i)
		for (int j = i + 1; j <= 2; ++j)
		{
			las = -1;
			for (int k = 0; k <= 6; ++k)
			{
				for (int p = 0; p <= 2; ++p)
					c[p][i] = a[k][p][1];
				for (int p = 0; p <= 2; ++p)
					c[p][j] = a[k][p][2];
				int t = 3 - i - j;
				for (int p = 0; p <= 2; ++p)
					c[p][t] = a[k][p][0];
				cout << c[0][0] << ' ' << c[0][1] << ' ' << c[0][2] << '\n'
					 << c[1][0] << ' ' << c[1][1] << ' ' << c[1][2] << '\n'
					 << c[2][0] << ' ' << c[2][1] << ' ' << c[2][2] << std::endl;
				int x;
				cin >> x;
				if (x == 6)
					return 0;
				if (las != -1 && x > las)
					s[i] = c[0][i] + c[1][i] + c[2][i];
				if (las != -1 && x < las)
					s[j] = c[0][j] + c[1][j] + c[2][j] + 1;
				las = x;
			}
		}
	if (!s[0])
		s[0] = 13 - s[1];
	if (!s[1])
		s[1] = 13 - s[2];
	if (!s[2])
		s[2] = 13 - s[0];
	for (int i = 0; i < 2; ++i)
		for (int j = i + 1; j <= 2; ++j)
		{
			las = -1;
			for (int k = 0; k <= 6; ++k)
			{
				for (int p = 0; p <= 2; ++p)
					c[p][i] = a[k][p][1];
				for (int p = 0; p <= 2; ++p)
					c[p][j] = a[k][p][2];
				int t = 3 - i - j;
				for (int p = 0; p <= 2; ++p)
					c[p][t] = a[k][p][0];
				cout << c[0][0] << ' ' << c[1][0] << ' ' << c[2][0] << '\n'
					 << c[0][1] << ' ' << c[1][1] << ' ' << c[2][1] << '\n'
					 << c[0][2] << ' ' << c[1][2] << ' ' << c[2][2] << std::endl;
				int x;
				cin >> x;
				if (x == 6)
					return 0;
				if (las != -1 && x > las)
					h[i] = c[0][i] + c[1][i] + c[2][i];
				if (las != -1 && x < las)
					h[j] = c[0][j] + c[1][j] + c[2][j] + 1;
				las = x;
			}
		}
	if (!h[0])
		h[0] = 13 - h[1];
	if (!h[1])
		h[1] = 13 - h[2];
	if (!h[2])
		s[2] = 13 - h[0];
	for (int i = 0; i < 3; ++i)
		swap(h[i], s[i]);
	dfs(0, 0);
	return 0;
}