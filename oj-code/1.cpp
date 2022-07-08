#include<bits/stdc++.h>
#define ll long long
#define ri register
#define all(x) (x).begin(),(x).end()
#define li(x) x.erase((sort(all(x)),unique(all(x))),x.end())
using namespace std;
vector<int>ans,Ans,s;
inline void sol(vector<int>&a,int k){
	printf("A:");for(int i:a)printf("%d ",i);
	printf("\n%d\n",k);
	if(k>1e6)return;
	li(a);
	a.erase((sort(all(a)),unique(all(a))),a.end());
	// sort(all(a));
	// a.erase(unique(all(a)),a.end());
	if(a.back()==0){
		if(ans.size()<Ans.size()||Ans.empty())Ans=ans;
		return;
	}
	bool flg=0;
	for(int i:a)if(i&1)flg=1;
	if(!flg){
		for(int&i:a)i>>=1;
		sol(a,k<<1);
	}else{
		vector<int>b;
		for(int i:a)b.emplace_back(i&1?(i+1)>>1:(i>>1));
		printf("a1:");for(int i:a)printf("%d ",i);puts("");
		printf("b1:");for(int i:b)printf("%d ",i);puts("");
		ans.emplace_back(-k),sol(b,k<<1),ans.pop_back();
		b.clear();
		for(int i:a)b.emplace_back(i&1?(i-1)>>1:(i>>1));
		printf("b2:");for(int i:b)printf("%d ",i);
		puts("");
		ans.emplace_back( k),sol(b,k<<1),ans.pop_back();
	}
}
int n;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),s.emplace_back(x);
	sol(s,1);
	for(int i:Ans)printf("%d ",i);
	return 0;
}
