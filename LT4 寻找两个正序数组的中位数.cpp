#include<bits/stdc++.h>
using namespace std;
#define siz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
class Solution {
	int kth(vector<int>&a,int i,vector<int>&b,int j,int k){
		if(siz(a)-i>siz(b)-j)return kth(b,j,a,i,k);
		if(siz(a)==i)return b[j+k-1];
		if(k==1)return min(a[i],b[j]);
		int p1=min(i+k/2,siz(a)),p2=j+k/2;
		if(a[p1-1]>b[p2-1])return kth(a,i,b,p2,k-k/2);
		return kth(a,p1,b,j,k-p1+i);
	}
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n=siz(nums1)+siz(nums2);
		if(n&1)return kth(nums1,0,nums2,0,n/2+1);
		return (kth(nums1,0,nums2,0,n/2)+kth(nums1,0,nums2,0,n/2+1))/2.;
	}
};