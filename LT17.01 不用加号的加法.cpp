#include<bits/stdc++.h>
using namespace std;
#define siz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
class Solution {
	int __add(unsigned a, unsigned b) {
		if(!a)return b;
		return __add(((a&b)<<1),(a^b));
	}
public:
	int add(int a, int b) {
		return __add(a,b);
	}
};