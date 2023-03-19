#include<bits/stdc++.h>
using namespace std;
using loli=long long;
#define siz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
		vector<int>nums1,nums2,target1,target2;
		loli res=0;
		for(int i=0;i<siz(nums);i++)(nums[i]&1?nums1:nums2).push_back(nums[i]);
		for(int i=0;i<siz(target);i++)(target[i]&1?target1:target2).push_back(target[i]);
		sort(all(nums1));sort(all(nums2));sort(all(target1));sort(all(target2));
		for(int i=0;i<siz(nums1);i++)if(nums1[i]<target1[i])res+=(target1[i]-nums1[i])/2;
		for(int i=0;i<siz(nums2);i++)if(nums2[i]<target2[i])res+=(target2[i]-nums2[i])/2;
		return res;
    }
};