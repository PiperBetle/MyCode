#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using std::cin;using std::cout;
struct pii{
	int fi,se,tag;
	pii():tag(0){}
}a[500007];
std::stack<pii>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i].fi;
	for(int i=1;i<=n;i++)cin>>a[i].se;
	bool f1=true,f2=true;
	for(int i=1;i<=n;i++){
		if(a[i].se!=n-i+1)f1=false;
		if(a[i].fi!=i)f2=false;
	}
	if(f1){
		for(int i=n;i>=1;i--){
			a[i].tag=1;
			if(a[i].fi==a[i+1].fi)a[i].tag+=a[i+1].tag;
		}
		while(q--){
			int l,r;cin>>l>>r;
			cout<<a[l].tag;
		}
		return 0;
	}
	while(q--){
		while(!s.empty())s.pop();
		int ans=0,l,r;cin>>l>>r;
		for(;l<=r;l++){
			for(;;){
				if(s.empty())break;
				if(a[l].fi!=s.top().fi&&a[l].se<s.top().se)break;
				s.pop();
			}
			ans+=s.empty();
			s.emplace(a[l]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}