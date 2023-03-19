#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int a[107],n,l;
bool used[107];
bool dfs(int cnt,int pre,int sum)
{
	if(cnt==n&&sum==0)return 1;
	if(sum==0)sum=l;
	for(int i=std::lower_bound(a+(sum!=l?pre+1:1),a+1+n,sum,std::greater<int>())-a;i<=n;i++){
		if(!used[i]&&a[i]<=sum){
			if(i>0&&!used[i-1]&&a[i-1]==a[i])continue;
			used[i]=true;
			if(dfs(cnt+1,i,sum-a[i]))return true;
			used[i]=false;
			if(sum==l||a[i]==sum)return false;
		}
	}
	return 0;
}
signed main(){
//	freopen("sticks.in","r",stdin);
//	freopen("sticks.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,total;
	while(cin>>n){
		if(!n)return 0;
		for(total=0,i=1;i<=n;i++)cin>>a[i],total+=a[i];
		memset(used,0,sizeof used);
		std::sort(a+1,a+1+n,std::greater<int>());
		for(l=a[1];l<=total;l++){
			if(total%l)continue;
			if(dfs(0,0,l)){cout<<l<<'\n';break;}
		}
	}
}