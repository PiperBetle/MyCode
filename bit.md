c++20 加入了一个叫做 `bit` 的库，不如来看看里面有什么？
## bit_cast
效果和 `reinterpret_cast` 类似，按二进制位取值，
```cpp
constexpr float N=100;
constexpr int M=std::bit_cast<int>(N);
constexpr float L=std::bit_cast<float>(N);
```
在这段代码里，$N=100.0$，虽然不知道 $M$ 的值但是可以确定 $L=100.0$，因为是按位取值。  
`std::bit_cast<any>(x)` 可以把 $x$ 转化成 `any` 类型，保留二进制。  
底层实现是 `__builtin_bit_cast(any,x)`
## byteswap
以每个字节为单位去 `reverse`，比如原来是 EFBEADDE，现在就是 DEADBEEF 了。似乎没啥用而且 c++23 的。  
`byteswap(x)` 这样就可以使用了。  
底层实现用到了 `__builtin_bswap16/32/64/128` 
## has_single_bit
判断一个数是否是 $2$ 的整次幂，但是直接 `x&x-1` 就可以了。或者 `popcount==1`。
`has_single_bit(x)` 这样就可以使用了。  
乐死了，底层实现也是这样的。
## bit_ceil
返回不小于 $x$ 的最小的 $2$ 的整数次幂。  
`bit_ceil(x)` 这样就可以使用了。  
底层实现用到了 `__builtin_clz`。
## bit_floor
返回不大于 $x$ 的最大的 $2$ 的整数次幂，等价于 `1<<std::__lg(x)`。  
`bit_floor(x)` 这样就可以使用了。  
底层实现用到了 `__builtin_clz`。
## bit_width
返回 $1+\log_2x$。  
`bit_width(x)` 这样就可以使用了。  
底层实现用到了 `__builtin_clz`。
## rotl/rotr
循环左/右移 $k$ 位。  
`bit_width(x,k)` 这样就可以使用了。  
底层实现就是左移右移的。
## countl/r_zero/one
- `countl_zero` 从最高位起计量连续的 0 位的数量
- `countl_one` 从最高位起计量连续的 1 位的数量
- `countr_zero` 从最低位起计量连续的 0 位的数量
- `countr_one` 从最低位起计量连续的 1 位的数量

注意这个函数只能 `unsigned`。  
`countl/r_zero/one(x)` 这样就可以使用了。  
底层实现是 `__builtin_clz` 和 `__builtin_ctz`。
## popcount
返回 $x$ 的值中为 $1$ 的位的数量。  
`popcount(x)` 这样就可以了。
底层实现就是 `__builtin_popcount`。
## endian
这是个枚举类型。如果是大端那么 `endian::native==endian::big`，小端那么 `endian::native==endian::little`，我也不知道这个有什么用。

---
以上这些函数，有些只能对 `unsigned` 类型使用，比如 `popcount`，如果对非 `unsigned` 类型使用可以写强转，`popcount(unsigned(x))` 或 `popcount<unsigned>(x)`。其实也可以在函数前加上两个下划线，这个不会对类型检查，`__popcount(x)`。