#include<bits/stdc++.h>
using namespace std;
#define siz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
class Solution {
	static constexpr int N=1001,M=__lg(N)+1;
	int st[M][N];
	int query(int l,int r){
		int t=__lg(r-l+1);
		return gcd(st[t][l],st[t][r-(1<<t)+1]);
	}
public:
	int subarrayGCD(vector<int>& nums, int k) {
		int n=siz(nums),ans=0;
		nums.insert(nums.begin(),0);
		for(int i=1;i<=n;i++)st[0][i]=nums[i];
		for(int j=1;(1<<j)<=n;j++)for(int i=1;i+(1<<j)-1<=n;i++)
			st[j][i]=gcd(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		for(int i=1;i<=n;i++){
			if(nums[i]<k)continue;
			int l=i;
			for(int j=__lg(n);~j;j--)
				if(l+(1<<j)<=n&&query(i,l+(1<<j))>k)l+=(1<<j);
			int r=max(i,l);
			for(int j=__lg(n);~j;j--)
				if(r+(1<<j)<=n&&query(i,r+(1<<j))>=k)r+=(1<<j);
			ans+=r-l;
			if(l==i&&nums[i]==k)ans++;
		}
		return ans;
	}
};
// int main(){
// 	int n,k;
// 	std::vector<int>nums;
// 	cin>>n>>k;	
// 	nums.resize(n);
// 	for(int&i:nums)cin>>i;
// 	cout<<Solution{}.subarrayGCD(nums,k);
// }