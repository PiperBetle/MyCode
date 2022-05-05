#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update>s;
using std::cin;using std::cout;
int a[100007];
signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	s.insert(a[n]);
	for(i=n-1;i>=1;i--)
		if(a[i]>a[i+1]){
			cout<<i<<'\n';
			for(j=1;j<=i;j++){
				cout<<s.order_of_key(a[j])+i-j<<' ';
				s.insert(a[j]);
			}
			return 0;
		}else s.insert(a[i]);
	return cout<<0,0;
}