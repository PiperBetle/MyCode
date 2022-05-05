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
	odt(int _l,int _r=-1,int _data=0):l(_l),r(_r),data(_data){}
	bool operator<(const odt &n)const{return l<n.l;}
};
int n,m,l,r;
std::set<odt>s;
inline auto split(int pos){
	auto it=s.lower_bound(pos);
	if(it!=s.end()&&it->l==pos)return it;
	it--;int l=it->l,r=it->r,k=it->data;
	s.erase(it);s.insert(odt(l,pos-1,k));
	return s.insert(odt(pos,r,k)).first;
}
inline void assign(int l,int r,int k){
	auto it_r=split(r+1),it_l=split(l);
	s.erase(it_l,it_r);
	auto it=s.insert(odt(l,r,k)).first;
	if(it==s.begin())return;
	it_l=it,it_r=it;it_l--;it_r++;
	l=it->l,r=it->r,k=it->data;
	if(it_r!=s.end()&&it_l->data==k&&it_r->data==k)l=it_l->l,r=it_r->r,s.erase(it_l,++it_r);
	else if(it_l->data==k)l=it_l->l,s.erase(it_l,++it);
	else if(it_r!=s.end()&&it_r->data==k)r=it_r->r,s.insert(it,++it_r);
	if(l!=r)s.insert(odt(l,r,k));
}
inline int query(int pos,int now=0,int ans=0){
	for(auto it:s){
		if(it.r>n||it.data!=0){now=0;continue;}
		if(now==0)ans=it.l;
		now+=it.r-it.l+1;
		if(now>=pos)return ans;
	}
	return 0;
}
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	n=read(),m=read();
	s.insert(odt(1,n));
	s.insert(odt(n+1,n+1,-1));
	while(m--)
		if(read()==1){write(l=query(r=read())),putchar('\n');if(l)assign(l,l+r-1,1);}
		else l=read(),r=read(),assign(l,l+r-1,0);
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}