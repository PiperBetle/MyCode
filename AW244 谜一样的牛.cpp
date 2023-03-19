#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using std::cin;using std::cout;
int a[100007],b[100007];
tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n;
	cin>>n;
	s.insert(1);a[1]=0;
	for(i=2;i<=n;i++)cin>>a[i],s.insert(i);
	for(i=n;i>=1;i--)s.erase(b[i]=*s.find_by_order(a[i]));
	for(i=1;i<=n;i++)cout<<b[i]<<'\n';
	return 0;
}