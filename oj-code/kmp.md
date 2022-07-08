kmp 是什么，什么是 kmp，不会完全不会。What Should I Do？  
算了，还是先看看 kmp 能 干什么。kmp 能够在线性时间内完成两个字符串的匹配（记长字符串为 $a$，短字符串为 $b$ ），那么如果每次在 $a$ 里枚举每个 $b$ 的开头，复杂度是 $\mathcal O(n\times m)$ 的，不够优秀，使用哈希倒是可以把时间变成 $\mathcal O(n+m)$，那么有没有其他做法呢？  
考虑这么一个优化，在 $a$ 里记录指针 $i$，在 $b$ 里记录指针 $j$，表示 $a_{i-j+1}$ 到 $a_i$ 和 $b_1$ 到 $b_j$ 完全相同。如果是暴力匹配，那就在 $j=m$ 时让 $j=0$，让 $i=i-j+1$，这样就可以匹配了。
```cpp
// a[size] 是越界的 STL下表从 0 开始
for(size_t i=1,j=0;i<a.size();i++){
	if(a[i]==b[j+1])j++;
	else i=i-j,j=0;
	if(j+1==b.size()){
		cout<<i-j+1<<'\n';
		i=i-j+1,j=0;
	}
}
```
考虑预处理出 $b$ 的 $kmp$ 数组，$kmp_i$ 表示从 $b_1$ 到 $b_{kmp_i}$ 和 $b_{i-kmp_i}$ 到 $b_i$ 完全相同，这样当匹配失败的时候（一般为了方便处理在每次循环开始都跳）跳到合法为止。  
这样不会影响答案的数量。因为扫描前面那些没有意义。扫 $b_1$ 到 $b_{kmp_i}$ 已经发现没法一样了；扫 $b_{kmp_i+1}$ 到 $b_{i-kmp_i-1}$ 连头都对不上；不如扫描后面的 $b_{i-kmp_i}$ 到 $b_{i-1}$，这样才可能扫到匹配，也就是前面那串没有用了喵。  
接下来考虑如何处理 $kmp$ 数组，发现可以直接拿自己跑 $kmp$，这样就处理完 $kmp$ 数组了。(切记从 $2$ 开始循环否则会死循环)
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using std::cin;using std::cout;
constexpr int kN=1e6;
std::string a,b;
int kmp[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	a.reserve(kN+1);b.reserve(kN+1);
	cin>>a>>b;a="~"+a;b="~"+b;
	for(size_t i=2,j=0;i<b.size();i++){
		while(j&&b[i]!=b[j+1])j=kmp[j];
		if(b[i]==b[j+1])j++;
		kmp[i]=j;
	}
	for(size_t i=1,j=0;i<a.size();i++){
		while(j&&a[i]!=b[j+1])j=kmp[j];
		if(a[i]==b[j+1])j++;
		if(j+1==b.size()){
			cout<<i-j+1<<'\n';
			j=kmp[j];
		}
	}
	for(size_t i=1;i<b.size();i++)cout<<kmp[i]<<' ';
	return 0;
}
```