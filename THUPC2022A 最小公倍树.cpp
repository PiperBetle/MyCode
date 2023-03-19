#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
int pt[1000007],mif[1000007],len=0;
bool pr[1000007];
struct trie{
	int data,min;
	std::vector<trie*>a;
	trie(){data=0,a.clear();}
}*root=new trie;
int ans=0;
inline void add(int n){
	trie *p=root;int mul=n;
	for(int j;n!=1;){
		for(j=0;j<p->a.size();j++)if(p->a[j]->data==mif[n])break;
		if(j<p->a.size()){
			p->min=std::min(p->min,n/mif[n]);
			p=p->a[j];
			continue;
		}
		trie *t=new trie;
		mul*=p->min;
		t->data=mif[n];
		t->min=n/mif[n];
		p->a.emplace_back(t);
		p=t;
		cout<<"display "<<n<<'\n';
		int miff=mif[n];
		while(n%miff==0)n/=miff;
	}
	cout<<"will plus "<<mul<<'\n';
	ans+=mul;
}
signed main(){
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int l,r;
	for(int i=2;i<=1000000;i++)
	{
		if(!pr[i])pt[++len]=i,mif[i]=i;
		for(int j=1;j<=len&&i*pt[j]<=1000000;j++)
		{
			pr[i*pt[j]]=1;
			mif[i*pt[j]]=pt[j];
			if(i%pt[j]==0)break;
		}
	}
	cin>>l>>r;
	root->min=l;
	for(l++;l<=r;l++)add(l);
	cout<<ans;
	return 0;
}