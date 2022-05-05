#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
struct BIT{
	int data[100007];
	void add(int x,int k=1){for(;x<=100000;x+=x&-x)data[x]+=k;}
	int sum(int x,int k=0){for(;x;x-=x&-x)k+=data[x];return k;}
}s1,s2;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;
	while(m--){
		int t,x,y;cin>>t>>x>>y;
		switch(t){
		case 1:s1.add(x);s2.add(y);break;
		case 2:cout<<s1.sum(y)-s2.sum(x-1)<<'\n';break;
		}
	}
	return 0;
}