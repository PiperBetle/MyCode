#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
using std::cin;
using std::cout;
struct point
{
	double x, y;
	bool operator<(const point &t) const
	{
		return x < t.x;
	}
};
inline double dis(point a, point b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
point a[100001], t[100001];
double find(int l, int r)
{
	if (l >= r)
		return 1e16;
	if (l + 1 == r)
	{
		if (a[l].y > a[r].y)
			std::swap(a[l], a[r]);
		return dis(a[l], a[r]);
	}
	int m = (l + r) >> 1, len = 0;
	double x = a[m].x, d = std::min(find(l, m), find(m + 1, r));
	for (int i = l; i <= r; i++)
		if (fabs(a[i].x - x) <= d)
			t[++len] = a[i];
	std::sort(t + 1, t + 1 + len, [](const point &a, const point &b)
			  { return a.y < b.y; });
	for (int i = 1; i < len; i++)
		for (int j = i + 1; j <= len && t[j].y - t[i].y <= d; j++)
			d = std::min(d, dis(t[i], t[j]));
	return d;
}
signed main()
{
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << std::setiosflags(std::ios::fixed) << std::setprecision(10);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	std::sort(a + 1, a + 1 + n);
	cout << find(1, n) << '\n';
	return 0;
}