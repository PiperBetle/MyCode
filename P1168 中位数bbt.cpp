#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using std::cin;using std::cout;
tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,t;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>t;s.insert(t);
		if(i&1)cout<<*s.find_by_order(i>>1)<<'\n';
	}
	return 0;
}
//* xzh啊xzh你在想peach