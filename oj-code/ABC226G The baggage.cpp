#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int long long
#define siz(x) int((x).size())
using std::cin;using std::cout;
int T,a[6],b[6];
inline void put(int x,int y){
	int z=std::min(a[x],b[y]);
	a[x]-=z,b[y]-=z,b[y-x]+=z;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>T;while(T--){
		a[0]=b[0]=0;
		for(int i=1;i<=5;i++)cin>>a[i];
		for(int i=1;i<=5;i++)cin>>b[i];
		put(5,5);put(4,4);put(4,5);
		put(3,3);put(3,5);put(3,4);
		for(int i=5;i>=2;i--)put(2,i);
		for(int i=5;i>=1;i--)put(1,i);
		cout<<(*std::max_element(a+1,a+6)?"No\n":"Yes\n");
	}
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}