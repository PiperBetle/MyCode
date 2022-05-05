#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
template<typename any>struct odt{
	struct odt_node{
		int l,r;mutable any data;
		odt_node(int _l,int _r=-1,any _data=0):l(_l),r(_r),data(_data){}
		bool operator<(const odt_node &t)const{return l<t.l;}
	};
	std::set<odt_node>s;
	void insert(int _l,int _r,any _data){s.insert(odt_node(_l,_r,_data));}
	auto begin(){return s.begin();}
	auto end(){return s.end();}
	auto split(int pos){
		auto it=s.lower_bound(pos);
		if(it!=s.end()&&it->l==pos)return it;
		it--;int l=it->l,r=it->r;any k=it->data;
		s.erase(it);s.insert(odt_node(l,pos-1,k));
		return s.insert(odt_node(pos,r,k)).first;
	}
	void assign(int l,int r,any k){
		auto it_r=split(r+1),it_l=split(l);
		s.erase(it_l,it_r);
		s.insert(odt_node(l,r,k));
	}
};
odt<int>s;
bool b[1007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	int n=read(),m=read(),ans=0;
	s.insert(1,n,0),s.insert(n+1,n+1,0);
	for(int i=1,l,r;i<=m;i++)l=read(),r=read(),s.assign(l,r,i);
	for(auto it:s)b[it.data]=true;
	for(int i=1;i<=m;i++)if(b[i])ans++;
	printf("%d",ans);
	return 0;
}