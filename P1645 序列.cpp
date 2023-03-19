#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
struct part{int l,r,c;bool operator<(const part &t){return r<t.r;}}a[30007];
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
		auto end=split(r+1),stt=split(l);
		s.erase(stt,end);
		s.insert(odt_node(l,r,k));
	}
};
odt<int>s;
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
#endif
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),ans=0;
	for(int i=1;i<=n;i++)a[i].l=read(),a[i].r=read(),a[i].c=read();
	std::sort(a+1,a+1+n);
	s.insert(1,n,0);s.insert(n+1,n+1,0);
	for(int i=1;i<=n;i++){
		auto end=s.split(a[i].r+1),stt=s.split(a[i].l);
		for(auto it=stt;it!=end;it++)a[i].c-=(it->r-it->l+1)*it->data;
		for(auto it=--end;a[i].c>0;it--)if(!it->data){
			int len=it->r-it->l+1;
			if(a[i].c>len)a[i].c-=len,ans+=len;
			else ans+=a[i].c,s.assign(it->r-a[i].c+1,a[i].r,1),a[i].c=0;
		}
	}
	printf("%d",ans);
	return 0;
}