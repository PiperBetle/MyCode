#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using std::cin;using std::cout;
template<typename any>struct odt{
	struct odt_node{
		int l,r;mutable any data;
		odt_node(int _l,int _r=-1,any _data=0):l(_l),r(_r),data(_data){}
		bool operator<(const odt_node &t)const{return l<t.l;}
	};
	std::set<odt_node>s;
	auto insert(int _l,int _r,any _data){return s.insert(odt_node(_l,_r,_data));}
	auto begin(){return s.begin();}
	auto end(){return s.end();}
	auto split(int pos){
		auto it=s.lower_bound(pos);
		if(it!=s.end()&&it->l==pos)return it;
		it--;int l=it->l,r=it->r;any k=it->data;
		s.erase(it);insert(l,pos-1,k);
		return insert(pos,r,k).first;
	}
	auto assign(int l,int r,any k){
		auto it_r=split(r+1),it_l=split(l);
		s.erase(it_l,it_r);
		return insert(l,r,k).first;
	}
};
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
odt<int>s;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	int n=read();s.insert(n+1,n+1,0);
	for(int i=1;i<=n;i++)s.insert(i,i,read());
	while(n--){
		int l=read(),r=read(),t=read(),ans=0;
		auto it_r=s.split(r+1),it_l=s.split(l);
		for(auto it=it_l;it!=it_r;it++)if(it->data==t)ans+=it->r-it->l+1;
		s.assign(l,r,t);
		printf("%d\n",ans);
	}
	return 0;
}