
#include<bits/stdc++.h>

using namespace std;

#define Reimu inline void // 灵梦赛高
#define Marisa inline int // 魔理沙赛高
#define Sanae inline bool // 早苗赛高

typedef long long LL;
typedef unsigned long long ULL;

typedef pair<int, int> Pii;
typedef tuple<int, int, int> Tiii;
#define fi first
#define se second

namespace FastInput {
	template<typename Ty>
	Reimu read(Ty &x) { // 默认读入整型 int, LL, Uint, ULL, ...
		x = 0;
		int f = 0;
		char c = getchar();
		for (; !isdigit(c); c = getchar()) f |= c == '-';
		for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
		if (f) x = -x;
	}

	template<>
	Reimu read(double &x) { // 读入浮点型 double
		x = 0;
		int f = 0;
		char c = getchar();
		for (; !isdigit(c); c = getchar()) f |= c == '-';
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
		if (c == '.') {
			double e = 1;
			for (c = getchar(); isdigit(c); c = getchar()) x += (c ^ 48) * (e *= .1);
		}
		if (f) x = -x;
	}

	template<>
	Reimu read(char &c) { // 读入字符 char
		do c = getchar(); while (!isgraph(c));
	}

	template<>
	Reimu read(string &s) { // 读入字符串 string
		s = "";
		char c = getchar();
		while (!isgraph(c)) c = getchar();
		for (; isgraph(c); c = getchar()) s += c;
	}

	template<typename Ty, typename...Args>
	Reimu read(Ty &x, Args &...args) { // 不定长传参
		read(x);
		read(args...);
	}
}
using namespace FastInput; // 使用快读

const int N = 1000010;

int n, m, c;
int a[N], ans[N];
unordered_map<int, vector<Tiii>> mp;

struct BIT {
	int c[N];
	Reimu init(int r) { memset(c + 1, 0, sizeof(int) * r); }
	Reimu add(int x, int v) { for (; x <= n; x += x & -x) c[x] += v; }
	Marisa ask(int x) { int res = 0; for (; x; x &= x - 1) res += c[x]; return res; }
} bit;

Reimu solve(vector<Tiii>&vec) {
	set<Pii> S;
	bit.init(n);
	for (int i = 1; i <= n; ++i) S.emplace(a[i], i);
	for (auto [o, l, r]: vec) {
		if (o) ans[o] = bit.ask(r) - bit.ask(l - 1);
		else {
			for (auto it = S.lower_bound({l, 0}); it->fi <= r; it = S.lower_bound({l, 0})) {
				bit.add(it->se, 1);
				S.erase(it);
			}
		}
	}
}

int main() {
	read(n, m, c);
	for (int i = 1; i <= n; ++i) read(a[i]);
	c = 0;
	for (int i = 1, o, l, r, k; i <= m; ++i) {
		read(o, l, r, k);
		if (o & 1) mp[k].emplace_back(0, l, r);
		else mp[k].emplace_back(++c, l, r);
	}
	for (auto&[k, vec]: mp) solve(vec);
	for (int i = 1; i <= c; ++i) printf("%d\n", ans[i]);
	return 0;
}