#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin,std::cout;
int get_len(int x,int l=0){while(x)x/=10,l++;return l;}
int gcd(int a,int b){return std::__gcd(a,b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}
struct fraction{
	int cnt,up,dw;
	fraction():cnt(0),up(0),dw(1){}
	fraction(int a,int b,int c):cnt(a),up(b),dw(c){}
	int real_up(){return cnt*dw+up;}
	fraction &updata(){int g=gcd(up,dw);up/=g,dw/=g;cnt+=up/dw;up%=dw;return *this;}
	friend int operator|(fraction &x,fraction &y){int l=lcm(x.dw,y.dw);x.up*=l/x.dw,y.up*=l/y.dw;return x.dw=y.dw=l;}
	fraction operator~(){return fraction(0,dw,real_up()).updata();}
	friend fraction operator+(fraction x,fraction y){int l=x|y;return fraction(x.cnt+y.cnt,x.up+y.up,l).updata();}
	friend fraction operator*(fraction x,fraction y){return fraction(0,x.real_up()*y.real_up(),x.dw*y.dw).updata();}
	friend fraction operator*(fraction x,int y){return fraction(x.cnt*y,x.up*y,x.dw).updata();}
	friend fraction operator/(fraction x,fraction y){return fraction(0,x.real_up()*y.dw,x.dw*y.real_up()).updata();}
	friend fraction operator/(fraction x,int y){return fraction(x.cnt*y,x.up,x.dw*y).updata();}
};
fraction ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)ans=ans+fraction(0,1,i);
	ans=ans*n;
	if(!ans.up)return cout<<ans.cnt,0;
	int sp1=get_len(ans.cnt),sp2=get_len(ans.dw);
	for(int i=1;i<=sp1;i++)cout<<' ';
	cout<<ans.up<<'\n'<<ans.cnt;
	for(int i=1;i<=sp2;i++)cout<<'-';
	cout<<'\n';
	for(int i=1;i<=sp1;i++)cout<<' ';
	cout<<ans.dw;
	return 0;
}