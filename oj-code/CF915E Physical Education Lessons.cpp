#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf;
int sta[50];
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
	#define putchar(x) ((p3-obuf<1000007)?(*p3++=(x)):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x)))
#endif
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
inline void write(int x){
	if(x==0){putchar('0');return;}
	int len=0;
	if(x<0)x=-x,putchar('-');
	while(x)sta[len++]=x%10+'0',x/=10;
	while(len--)putchar(sta[len]);
}
struct odt{
	int l,r;mutable int data;
	bool operator<(const odt &n)const{return l<n.l;}
};
int ans;
std::set<odt>s;
inline auto split(int pos){
	auto it=s.lower_bound(odt{pos,-1,0});
	if(it!=s.end()&&it->l==pos)return it;
	it--;int l=it->l,r=it->r,t=it->data;
	s.erase(it);s.insert(odt{l,pos-1,t});
	return s.insert(odt{pos,r,t}).first;
}
inline void assign(int l,int r,int k){
	auto it_r=split(r+1),it_l=split(l);
	for(auto it=it_l;it!=it_r;it++)ans-=(it->r-it->l+1)*it->data;
	ans+=(r-l+1)*k;
	s.erase(it_l,it_r);
	s.insert(odt{l,r,k});
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int n=read(),m=read();ans=n;
	s.insert(odt{1,n,1});
	s.insert(odt{n+1,n+1,0});
	while(m--){
		int l=read(),r=read();
		assign(l,r,read()-1);
		write(ans);putchar('\n');
	}
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}