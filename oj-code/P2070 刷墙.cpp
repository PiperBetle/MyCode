#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin,std::cout;
struct line{int l,r;bool operator<(const line &t){return l<t.l;}};
std::vector<line>a;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,k=2,ans=0;cin>>n;
	for(int i=1,p=0;i<=n;i++){
		int t;char c;cin>>t>>c;
		switch(c){
		case 'L':a.emplace_back(p,-1);a.emplace_back(p-=t,1);break;
		case 'R':a.emplace_back(p,1);a.emplace_back(p+=t,-1);break;
		}
	}
	std::sort(a.begin(),a.end());
	for(int i=1,p=a[0].r;i<(n<<1);i++){
		if(p>=k)ans+=a[i].l-a[i-1].l;
		p+=a[i].r;
	}
	cout<<ans<<'\n';
	return 0;
}