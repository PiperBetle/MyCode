#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using std::cin;using std::cout;
struct stn{
	stn *l=nullptr,*r=nullptr;int num=0;long long s[5]={};
	void merge(){num=l->num+r->num;for(int i=0;i<5;i++)s[i]=l->s[i]+r->s[((i-l->num)%5+5)%5];}
}*root=new stn;
void add(stn *&now,int k,int l,int r){
	if(l==r){now->s[1]=k;now->num=1;return;}int mid=(l+r)>>1;
	if(!now->l){now->l=new stn;}if(!now->r){now->r=new stn;}
	k<=mid?add(now->l,k,l,mid):add(now->r,k,mid+1,r);now->merge();
}
void del(stn *&now,int k,int l,int r){
	if(l==r){now->s[1]=now->num=0;return;}int mid=(l+r)>>1;
	k<=mid?del(now->l,k,l,mid):del(now->r,k,mid+1,r);now->merge();
}
std::string s;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T,t;cin>>T;while(T--){
		switch(cin>>s;s[0]){
		case 'a':cin>>t;add(root,t,1,1000000000);break;
		case 'd':cin>>t;del(root,t,1,1000000000);break;
		case 's':cout<<root->s[3]<<'\n';break;
		}
	}
	return 0;
}