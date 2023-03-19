#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<random>
using std::cin;using std::cout;
std::mt19937 rng(std::random_device{}());
struct treap{
	struct node{
		node *ls=nullptr,*rs=nullptr;
		int val=0,pri=rng(),siz=0;
		node(int k):ls(nullptr),rs(nullptr),val(k),pri(rng()),siz(1){}
		node *updata(){siz=1+(ls?ls->siz:0)+(rs?rs->siz:0);return this;}
	};
	node *rt=nullptr;
	node *merge(node *x,node *y){
		if(!x)return y;
		if(!y)return x;
		if(x->pri<y->pri)return x->rs=merge(x->rs,y),x->updata();
		else return y->ls=merge(x,y->ls),y->updata();
	}
	void split(node *now,int k,node *&x,node *&y){
		if(!now){x=y=nullptr;return;}
		if(now->val<=k)x=now,split(now->rs,k,now->rs,y);
		else y=now,split(now->ls,k,x,now->ls);
		now->updata();
	}
	node *kth(node *now,int k){
		for(;;){
			int sum=(now->ls)?now->ls->siz:0;
			if(k<=sum)now=now->ls;
			else if(k==sum+1)return now;
			else k-=sum+1,now=now->rs;
		}
	}
	void insert(int k){
		node *x=nullptr,*y=nullptr;
		split(rt,k,x,y);
		rt=merge(merge(x,new node(k)),y);
	}
	void erase(int k){
		node *x=nullptr,*y=nullptr,*z=nullptr;
		split(rt,k,x,z);
		split(x,k-1,x,y);
		y=merge(y->ls,y->rs);
		rt=merge(merge(x,y),z);
	}
	int order(int k){
		node *x=nullptr,*y=nullptr;
		split(rt,k-1,x,y);
		int res=(x?x->siz:0)+1;
		rt=merge(x,y);
		return res;
	}
	int operator[](int k){
		return kth(rt,k)->val;
	}
	int prev(int k){
		node *x=nullptr,*y=nullptr;
		split(rt,k-1,x,y);
		int res=kth(x,x->siz)->val;
		rt=merge(x,y);
		return res;
	}
	int next(int k){
		node *x=nullptr,*y=nullptr;
		split(rt,k,x,y);
		int res=kth(y,1)->val;
		rt=merge(x,y);
		return res;
	}
}s;
signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;for(int t,a;T--;){
		cin>>t>>a;switch(t){
		case 1:s.insert(a);break;
		case 2:s.erase(a);break;
		case 3:cout<<s.order(a)<<'\n';break;
		case 4:cout<<s[a]<<'\n';break;
		case 5:cout<<s.prev(a)<<'\n';break;
		case 6:cout<<s.next(a)<<'\n';break;
		}
	}
	return 0;
}