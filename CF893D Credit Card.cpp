//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using std::cin;using std::cout;
constexpr int N=1e5+1;
int n,m,a[N],ans,s1,s2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)
		if(cin>>x,x){
			if((s1+=x)>m)return cout<<"-1",0;
			if((s2+=x)>m)s2=m;
		}else{
			if(s1<0)s1=0;
			if(s2<0)s2=m,ans++;
		}
	cout<<ans;
	return 0;
}