#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
struct point{int x,y;}a[107];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++){
		if((a[k].x-a[j].x)*(a[j].y-a[i].y)==(a[k].y-a[j].y)*(a[j].x-a[i].x))
			return cout<<"Yes",0;
	}
	cout<<"No";
	return 0;
}