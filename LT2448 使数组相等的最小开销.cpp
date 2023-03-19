#include<bits/stdc++.h>
using namespace std;
#define siz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using loli=long long;
using pii=std::pair<int,int>;
class Solution {
public:
	long long minCost(vector<int>& nums, vector<int>& cost) {
		int n=siz(nums),m=0,k;
		loli res=0;
		vector<pii>a;
		for(int i=0;i<n;i++)a.emplace_back(nums[i],cost[i]),m+=cost[i];
		sort(all(a));m/=2;
		for(int i=0;i<n;i++)if(m<=a[i].se){k=a[i].fi;break;}else m-=a[i].se;
		for(int i=0;i<n;i++)res+=1ll*abs(k-a[i].fi)*a[i].se;
		return res;
	}
};