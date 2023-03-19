#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int n,b[107]={1},dep;
bool dfs(int now){
	if(now==dep)return b[dep-1]==n;
	if((b[now-1]<<(dep-now))<n)return false;
	for(int i=now-1;i>=0;i--)for(int j=i;j>=0;j--){
		int num=b[i]+b[j];
		if(num>n||num<=b[now-1])continue;
		b[now]=num;
		if(dfs(now+1))return true;
	}
	return false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n){
		if(!n)return 0;
		for(dep=1;;dep++)if(dfs(1))break;
		for(int i=0;i<dep;i++)cout<<b[i]<<' ';
		cout<<'\n';
	}
	return 0;
}