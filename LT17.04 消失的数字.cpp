#include<bits/stdc++.h>
using namespace std;
#define siz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int n=siz(nums),x=0;
		for(int i=1;i<=n;i++)x^=i;
		for(int i:nums)x^=i;
		return x;
    }
};