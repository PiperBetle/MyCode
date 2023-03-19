`ranges` 库是 c++20 开始具有的语法，对应的头文件是 `#include<ranges>`。为了防止 CE 我一般都这么写：
```cpp
#if __cplusplus>=202002L
#include<ranges>
namespace vw=std::views;
#endif
```

`ranges` 最有用的操作是 `for(int i:v)` 这种 `for` 循环。如果想反向输出直接 `for(int i:v|reverse)` 就可以了。

另外还有一些其他的范围适配器。
- `filter`：`filter([](int x){return x&1;})` 表示只取范围内的奇数。
- `transform`：`transform([](int x){return x*x;})` 表示取范围内数前先平方。
- `take`：`take(x)` 表示取范围前 $x$ 个。
- `take_while`：`take_while([](int x){return x&1;})` 表示一直取直到取到偶数为止。
- `take`：`take(x)` 表示不取范围前 $x$ 个。
- `take_while`：`take_while([](int x){return x&1;})` 表示一直不取直到取到偶数为止。
- `reverse`：`reverse` 表示反向迭代序列。
- `elements`：`elements(x)` 表示只取 `tuple` 的第 $x+1$ 个元素。
- `keys`：`keys` 表示只取 `pair` 的 `first`。
- `values`：`values` 表示只取 `pair` 的 `second`。
- `adjacent`：`adjacent(x)` 表示取每个长度为 $x$ 的 `tuple`，是引用。

上面这些都是用 `operator|` 和范围适配器连接起来的，还有几个另外的范围适配器：
- `spilt`：`spilt(v,x)`，这个的返回值是一个可以用范围遍历的东西，也就是范围适配器。
```cpp
std::vector v={20,1,12,4,1,3,10,1};
for(auto i:split(v|reverse,1)){
	for(int k:i)cout<<k<<' ';
	cout<<'\n';
}
```
- `counted`：`counted(p,x)`是以 $p$ 为初始迭代器向后拓展 $x$ 的可迭代对象。
```cpp
std::vector v={20,1,12,4,1,3,10,1};
for(int i:counted(vec.begin()+1,3))
	cout<<i<<' ';

```
- `join`：直接连接，表示这个范围适配器拉平一次的结果。如果这么写 $i$ 的类型是 `vector<int>` 而不是 `int`，只会拉平一次！所以会 CE。
```cpp
std::vector<std::vector<std::vector<int>>>v{{{20,1},{12}},{{4,1},{3,10,1}}};
for(auto i:v|join)cout<<i<<' ';
```
- `join_with`：和 `join` 效果一样，`join_with(x)` 表示每次拉平一块后加入一个 $x$。
- `zip`：把几个范围适配器每次取一个组成 `tuple` 的范围适配器。这里直接放[这里](https://zh.cppreference.com/w/cpp/ranges/zip_view)的代码，不知道为什么没有 `zip`：
```cpp
auto x=std::vector{1,2,3,4};
auto y=std::list<std::string>{"α","β","γ","δ","ε"};
auto z=std::array{'A','B','C','D','E','F'};
for(std::tuple<int&,std::string&,char&>i:zip(x,y,z))
	cout<<get<0>(i)<<' '<<get<1>(i)<<' '<<std::get<2>(i)<<'\n',
	std::get<char&>(i)+=('a'-'A');
cout<<'\n';
for(auto i:z)cout<<i<<' ';
```
- `slide`：`slide(x)` 返回范围适配器，枚举左端点，右端点是左端点移 $x$ 后的结果。
- `chunk`：`chunk(x)` 返回范围适配器，枚举左端点，右端点是左端点移 $x$ 后的结果，但是下一个左端点是这次的右端点的下一个。
- `chunk_by`：`chunk_by(x)` 表示如果两个元素不满足 $x$ 的关系，就在这里割一刀，每次返回两刀之间的范围适配器。
- `empty`：产生一个空的范围适配器。
- `single`：`single(x)` 能产生只有 $x$ 这个元素的范围适配器。
- `iota`：`single(x,y)` 重复 $x$，每次累加，如果大于等于 $y$ 就退出，$y$ 不写就一直循环下去。
- `istream`：`istream<t>(x)` 从 $x$ 的流里以 $t$ 的类型构造，`for(int i:istream<int>(cin))`。
- `repeat`：`repeat(x,y)` 重复 $x$ 的值 $y$ 次，$y$ 不写表示重复。

另外所有 `ranges` 都具有惰性求值的，不去访问就没有时间复杂度。
```cpp
std::vector v1={1,3,4,2,5};
auto v2=v1|reverse|transform([](int x){return x*x;});
```
这样就可以产生一个是 `v1` 反向的，每个数都是 `v1` 平方的范围适配器。