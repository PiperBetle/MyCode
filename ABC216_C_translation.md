### 题意
有一个空盒子，里面没有球。
- 操作 $A$：放入一个球。
- 操作 $B$：球的数量翻倍。

给定 $n$，输出一串操作序列使操作完后球的数量恰好为 $n$ 个。操作的数量最多 $120$ 次。  
可以证明一定存在至少一种方案。
### 数据范围
$1\le n\le10^{18}$  

---
### 输入格式
一行 $1$ 个整数 $n$。
### 输出格式
长度小于 $120$，由 `A` 或 `B` 组成的一串操作序列。

---
### 样例输入1
```
5
```
### 样例输出1
```
AABA
```
### 样例解释1
$0\stackrel A{\rightarrow}1\stackrel A{\rightarrow}2\stackrel B{\rightarrow}4\stackrel A{\rightarrow}5$  
比如 `AAAAA` 也是正确答案。

---
### 样例输入2
```
14
```
### 样例输出2
```
BBABBAAAB
```
### 样例解释2
$0\stackrel B{\rightarrow}0\stackrel B{\rightarrow}0\stackrel A{\rightarrow}1\stackrel A{\rightarrow}2\stackrel A{\rightarrow}4\stackrel A{\rightarrow}5\stackrel A{\rightarrow}6\stackrel A{\rightarrow}7\stackrel B{\rightarrow}14$  
并不要求是最短序列。