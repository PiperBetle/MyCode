#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<map>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
struct node{
	loli val;
	std::string pre,suf;
	node(const std::string &s=""):val(0){
		if(!s.empty())pre=s.substr(0,std::min(siz(s),3));
		if(!s.empty())suf=s.substr(std::max(siz(s)-3,0));
		for(int i=0;i<=siz(s)-4;i++)val+=s.substr(i,4)=="haha";
	}
	friend node operator+(const node &a,const node &b){
		node c;
		if(siz(a.pre)<3||siz(b.pre)<3)c=a.suf+b.pre,c.val+=a.val+b.val;
		else c.pre=a.pre,c.suf=b.suf,c.val=a.val+b.val+node(a.suf+b.pre).val;
		return c;
	}
};
std::map<std::string,node>mp;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		mp.clear();
		std::string s0,s1,s2,op;
		int n;cin>>n;while(n--){
			cin>>s0>>op;
			if(op.front()==':')cin>>s1,mp[s0]=s1;
			else cin>>s1>>s2>>s2,mp[s0]=mp[s1]+mp[s2];
		}
		cout<<mp[s0].val<<'\n';
	}
	return 0;
}