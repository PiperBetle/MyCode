#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using std::cin;using std::cout;
struct BIT{
	int data[1007];
	void add(int x,int k=1){for(;x<=1000000;x+=x&-x)data[x]+=k;}
	int sum(int x,int k=0){for(;x;x-=x&-x)k+=data[x];return k;}
	int query(int l,int r){return sum(r)-sum(l-1);}
};
BIT s1[2007],s2[2007];
query(t1,r)*r-query(t2,r)-query(t1,l-1)*(l-1)+query(t2,l-1)
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	char c;int n,m;cin>>c>>n>>m;
	while(cin>>c){
		int x1,y1,x2,y2,k;
		switch(c){
		case 'L':
			cin>>x1>>y1>>x2>>y2>>k;
			for(int i=x1;i<=x2;i++)s[i].add(y1,y2,k);
			break;
		case 'k':
			cin>>x1>>y1>>x2>>y2;k=0;
			for(int i=x1;i<=x2;i++)k+=s[i].query(y1,y2);
			cout<<k<<'\n';
			break;
		}
	}
	return 0;
}