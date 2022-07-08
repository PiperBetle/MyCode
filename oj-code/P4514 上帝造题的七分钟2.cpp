#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using std::cin;using std::cout;
constexpr int kN=2049;
int n,m,k;
char c;
struct BIT_2{
	struct BIT_node{
		int data[kN][kN]={};
		int *operator[](int x){return data[x];}
		inline void updata(int x,int y,int k){for(int i=x;i<=n;i+=i&-i)for(int j=y;j<=m;j+=j&-j)data[i][j]+=k;}
		inline int query(int x,int y){int k=0;for(int i=x;i;i-=i&-i)for(int j=y;j;j-=j&-j)k+=data[i][j];return k;}
	}a,b,c,d;
	void updata(int x,int y,int k){
		a.updata(x,y,k),b.updata(x,y,k*x),c.updata(x,y,k*y),d.updata(x,y,k*x*y);
	}
	int query(int x,int y){
		return a.query(x,y)*(x*y+x+y+1)-b.query(x,y)*(y+1)-c.query(x,y)*(x+1)+d.query(x,y);
	}
}bt;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>c>>n>>m;
	while(cin>>c){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(c=='L')cin>>k,bt.updata(x1,y1,k),bt.updata(x2+1,y1,-k),bt.updata(x1,y2+1,-k),bt.updata(x2+1,y2+1,k);
		else cout<<bt.query(x2,y2)-bt.query(x1-1,y2)-bt.query(x2,y1-1)+bt.query(x1-1,y1-1)<<'\n';
	}
	return 0;
}