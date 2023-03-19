#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#define int long long
using std::cin;using std::cout;
constexpr int inf=1e18;
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
	void inv(int l,int r){
		auto it_r=split(r+1),it_l=split(l);
		for(auto it=it_l;it!=it_r;it++)it->data=!it->data;
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
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n=read();s.insert(1,inf,0);s.insert(inf+1,inf+1,0);
	while(n--){
		int t=read(),l=read(),r=read();
		switch(t){
		case 1:s.assign(l,r,1);break;
		case 2:s.assign(l,r,0);break;
		case 3:s.inv(l,r);break;
		}
		for(auto it=s.begin();;it++)if(!it->data){printf("%lld\n",it->l);break;}
	}
	return 0;
}