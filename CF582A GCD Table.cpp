#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
using std::cin;using std::cout;
inline int gcd(int a, int b){
	if(!a)return b;
	if(!b)return a;
	int t=__builtin_ctz(a|b);
	a>>=__builtin_ctz(a);
	do{
		b>>=__builtin_ctz(b);
		if(a>b)std::swap(a,b);
		b-=a;
	}while(b);
	return a<<t;
}
std::unordered_map<int,int>map;
int a[250007];
std::vector<int>b;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m;
	cin>>n;m=n*n;
	for(i=1;i<=m;i++)cin>>a[i],map[a[i]]++;
	std::sort(a+1,a+1+m,std::greater<int>());
	for(i=1;i<=m;i++){
		if(!map[a[i]])continue;
		for(auto it:b)map[gcd(it,a[i])]-=2;
		b.emplace_back(a[i]);
		map[a[i]]--;
	}
	for(auto it:b)cout<<it<<' ';
	return 0;
}