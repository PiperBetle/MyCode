```cpp
namespace f1{
	namespace f2{
		struct cow{
			friend void solve(cow){cout<<"f1::f2::cow";}
		};
	}
	void solve(f2::cow){cout<<"f1\n";}
	namespace f2{
		void solve(cow){cout<<"f1::f2\n";}
	}
}
void solve(f1::f2::cow){cout<<"::";}
namespace g1{
	void solve(f1::f2::cow){cout<<"g1";}
	namespace g2{
		void solve(f1::f2::cow){cout<<"g1::g2";}
		void print(){solve(f1::f2::cow{});}
	}
}
```
相信看到这段代码，很多人都会感到害怕，这个 `print` 究竟会输出什么呢？其实这段代码会 `CE`。

先说说什么是 `adl`，很好理解，就是调用的函数会在参数的命名空间里查找。比如我有个 `std::string b`，我要统计里面有多少个空格，那就是 `std::count(b.begin(),b.end(),' ')`，返回值就是空格的数量。  
看这么一段代码：
```cpp
namespace ff{
	struct cow{};
	cow operator+(const cow &x,const cow &y){
		return cow{};
	}
}
ff::cow solve(){
	ff::operator+(ff::cow{},ff::cow{});
	return ff::cow{}+ff::cow{};
}
```
假如没有 `adl`，`solve` 里面的加法必须以第一种方式显式调用这样才能调用到这个函数，但是有 `adl` 的情况下，`ff::operator+` 可以直接由 `ff::cow` 去 `adl` 到。让很多情况方便了不少。

接下来看看上面那段代码，首先排除的是 `::solve` 和 `g1::solve`，都被 `g1::g2::solve` 给遮盖了（局部屏蔽全局），`f1::solve` 由于 `adl` 只会往外找同一层命名空间，所以并不会被 `adl` 到。这个时候 `g1::g2::solve`（和函数本身就在同一命名空间） 和 `f1::f2::solve`（通过 `adl` 找到） 和 `f1::f2::cow::solve`（类内友元，也能通过 `adl` 找到）具有同等地位，所以就会导致 CE。

至于 `adl` 的实际价值就是节省码量，拓宽函数的寻找范围，很多本来要 `std::` 的都可以省略。
```cpp
endl(std::cout<<a[2]);
flush(std::cout<<"! 3\n");// cout 作参数
std::cout<<std::endl;// 注意这里的函数是 operator<<
operator<<(std::cout,std::endl);// 注意这里的函数是 operator<<
(std::endl)(std::cout<<"4\n");// 加上括号，没法 adl，必须写 std::endl
std::pair<int,int>a[3];
sort(a,a+3);// 指针也可以 adl
```