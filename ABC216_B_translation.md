### 题意 
给定 $n$ 个字符串对 $s_i$ 和 $t_i$，问是否存在相同的字符串对。存在输出 `Yes`，否则输出 `No`。
### 数据范围
$2\le n\le1000$  
$1\le |s_i|,|t_i|\le10$

---
### 输入格式
第一行 $1$ 个整数 $n$。
接下来 $n$ 行，每行两个字符串 $s_i$ 和 $t_i$。
### 输出格式
一行一个字符串 `Yes` 或 `No`。

---
### 样例输入1
```
3
tanaka taro
sato hanako
tanaka taro
```
### 样例输出1
```
Yes
```
### 样例解释1
第一个字符串对和第三个一样。

---
### 样例输入2
```
3
saito ichiro
saito jiro
saito saburo
```
### 样例输出2
```
No
```
### 样例解释2
不存在相同的字符串对。

---
### 样例输入3
```
4
sypdgidop bkseq
bajsqz hh
ozjekw mcybmtt
qfeysvw dbo
```
### 样例输出3
```
No
```