在 c++ 中，有一个东西叫做 template，也就是中文里的模板，c++ 的 STL 以及许多函数都用到了 template，template 指出了泛型编程的一条道路。  
最经典的问题是写一个函数，返回两个数的较小值。
```cpp
inline int min(const int &a,const int &b){
	return a<b?a:b;
}
```
这段代码非常浅显易懂，但是只支持 int 类型的变量，想要支持其他类型，必须通过 c++ 的重载函数才能实现。
```cpp
inline double min(const double &a,const double &b){
	return a<b?a:b;
}
```
这样要写很多很多函数才能实现，而且还不支持用户自定义类型，非常不实用。这个时候就容易想到使用 #define 预编译指令实现。  
PS：c++ 重载函数的原理是 SFINAE 原则，不匹配不报错而是试图匹配其他的同名函数。
```
#define min(x,y)((x)<(y)?(x):(y))
```
尽管这样实现了要求，但是首先 #define 不安全，其次就是遇到有副作用的运算比如自增运算符就会产生问题……当然可以通过多行 #define 实现。但是最简单的方法还是模板：
```cpp
template<typename any>
inline any min(const any &a,const any &b){
	return a<b?a:b;
}
```
这样仅此一个函数就实现了所有功能。如果对于用户自定义的变量进行比较，可以对用户变量进行重载运算符小于号解决，或者通过模板特化：
```cpp
struct modint{int data;};
friend inline bool operator<(const modint &x,const modint &y){
	return x.data<y.data;
}// 重载运算符
inline modint min(const modint &x,const modint &y){
	return x.data<y.data?x:y;
}// 模板特化
```
但是要是不只有一个类型而是一系列类型都要特化模板，比如说为所有 unsigned 类型写一个 lowbit，这要怎么办呢？要是全部重载函数，unsigned short，unsigned int，unsigned long，unsigned long long，太多了！而如果直接写模板有时候又不想传入 unsigned 类型，这个时候就要用到 enable_if 了。
enable_if 听上去是个函数实际上是个函数实际上是个 struct，构造十分巧妙，第一个参数强制要求是 true，起到了 if 判断作用：如果是 false，直接跳过。
这里给出 std 命名空间里 enable_if 的实现方式：
```cpp
	// Partial specialization for true.
	template<typename _Tp>
		struct enable_if<true, _Tp>
		{ typedef _Tp type; }
```
再贴一个使用 enable_if 实现的 lowbit：
```cpp
template<typename any>
inline typename std::enable_if<std::is_unsigned<any>::value,any>::type lowbit(const any &x){
	return x&-x;
}
```
可以发现原来本来应该写 any 的位置变成了很长一串：首先由 typename 打头阵，指出后面是个类型而不是个普通类型，然后是个 enable_if，逗号左边是判别式，这里使用 std::is_unsigned 进行判别，但是 is_unsigned 本质上也不是个函数没有返回值，就使用在里面 typedef 的 value 当成返回类型即可，也就是 any，逗号后面是这个函数真正的返回类型，这里直接使用 any 就行了，因为 std::enable_if 也不是个函数，只能使用在 std::enable_if 里 typedef 的 type 当成返回类型即可。至于其他部分和普通模板一模一样。
为了加深印象，我就放另外一个由 std::enable_if 实现的快读作为示范：
```cpp
class fastIO
{
private:
	char ibuf[1000007], *p1 = ibuf, *p2 = ibuf, obuf[1000007], *p3 = obuf, sta[70];
	int get() { return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1000007, stdin), p1 == p2) ? EOF : *p1++; }
	void put(const char &x) { p3 - obuf < 1000007 ? *p3++ = (x) : (fwrite(obuf, p3 - obuf, 1, stdout), p3 = obuf, *p3++ = (x)); }

public:
	int flush()
	{
		fwrite(obuf, p3 - obuf, 1, stdout);
		return 0;
	}
	fastIO &operator>>(char &t)
	{
		for (t = get(); isspace(t); t = get())
			;
		return *this;
	}
	fastIO &operator>>(char *t)
	{
		for (int c = get(); c != 10; c = get())
			*t = c, t++;
		*t = 0;
		return *this;
	}
	fastIO &operator>>(std::string &t)
	{
		t.clear();
		for (int c = get(); !isspace(c); c = get())
			t.push_back(c);
		return *this;
	}
	template <typename any>
	typename std::enable_if<std::is_signed<any>::value, fastIO>::type &operator>>(any &t)
	{
		t = 0;
		bool y = 0;
		int c = get();
		for (; !isdigit(c); c = get())
			if (c == 45)
				y = true;
		for (; isdigit(c); c = get())
			t = t * 10 + (c ^ 48);
		if (y == 1)
			t = -t;
		return *this;
	}
	fastIO &operator>>(__int128_t &t)
	{
		t = 0;
		bool y = 0;
		int c = get();
		for (; !isdigit(c); c = get())
			if (c == 45)
				y = true;
		for (; isdigit(c); c = get())
			t = t * 10 + (c ^ 48);
		if (y == 1)
			t = -t;
		return *this;
	}
	template <typename any>
	typename std::enable_if<std::is_unsigned<any>::value, fastIO>::type &operator>>(any &t)
	{
		t = 0;
		int c = get();
		for (; !isdigit(c); c = get())
			;
		for (; isdigit(c); c = get())
			t = t * 10 + (c ^ 48);
		return *this;
	}
	fastIO &operator>>(__uint128_t &t)
	{
		t = 0;
		int c = get();
		for (; !isdigit(c); c = get())
			;
		for (; isdigit(c); c = get())
			t = t * 10 + (c ^ 48);
		return *this;
	}
	fastIO &operator<<(const char &t)
	{
		put(t);
		return *this;
	}
	fastIO &operator<<(const char *t)
	{
		for (; *t; t++)
			put(*t);
		return *this;
	}
	fastIO &operator<<(const std::string &t)
	{
		for (const char &it : t)
			put(it);
		return *this;
	}
	template <typename any>
	typename std::enable_if<std::is_signed<any>::value, fastIO>::type &operator<<(any t)
	{
		if (!t)
		{
			put(48);
			return *this;
		}
		int len = 0;
		if (t < 0)
			t = -t, put(45);
		while (t)
			sta[len++] = t % 10 + 48, t /= 10;
		while (len--)
			put(sta[len]);
		return *this;
	}
	fastIO &operator<<(__int128_t t)
	{
		if (!t)
		{
			put(48);
			return *this;
		}
		int len = 0;
		if (t < 0)
			t = -t, put(45);
		while (t)
			sta[len++] = t % 10 + 48, t /= 10;
		while (len--)
			put(sta[len]);
		return *this;
	}
	template <typename any>
	typename std::enable_if<std::is_unsigned<any>::value, fastIO>::type &operator<<(any t)
	{
		if (!t)
		{
			put(48);
			return *this;
		}
		int len = 0;
		while (t)
			sta[len++] = t % 10 + 48, t /= 10;
		while (len--)
			put(sta[len]);
		return *this;
	}
	fastIO &operator<<(__uint128_t t)
	{
		if (!t)
		{
			put(48);
			return *this;
		}
		int len = 0;
		while (t)
			sta[len++] = t % 10 + 48, t /= 10;
		while (len--)
			put(sta[len]);
		return *this;
	}
} fio;
// 使用了 VScode 格式化，所以这个类的码风不同
```