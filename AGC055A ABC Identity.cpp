#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e6+1;
int n,ans[kN];
std::string s;
constexpr auto find(char c){
	if(c=='A')return std::make_pair('B','C');
	if(c=='B')return std::make_pair('A','C');
	return std::make_pair('A','B');
}
using pcc=std::pair<char,char>;
constexpr char operator&(const pcc &x,const pcc &y){
	return x.first==y.first||x.first==y.second?x.first:x.second;
}
struct{
	struct BIT{
		int tr[kN];
		void updata(int x,int k=1){for(;x<=n;x+=x&-x)tr[x]+=k;}
		int query(int x1,int x2){
				int k1=0;for(x1--;x1;x1-=x1&-x1)k1+=tr[x1];
				int k2=0;for(;x2;x2-=x2&-x2)k2+=tr[x2];
				return k2-k1
			;}
	}A,B,C;
	constexpr BIT &operator[](char c){
		if(c=='A')return A;
		if(c=='B')return B;
		return C;
	}
}mp;
int next(int p1,char c){
	int p2=p1;
	for(int i=1<<std::__lg(n);i;i>>=1)
		if(p2+i<=n&&mp[c].query(p1+1,p2+i)==0)p2+=i;
	return ++p2;
}
int prev(int p1,char c){
	int p2=p1;
	for(int i=1<<std::__lg(n);i;i>>=1){
		if(p2-i>=1&&mp[c].query(p2-i,p1-1)==0)p2-=i;
	}
	// assert(s[p2-1]==c);
	return --p2;
}
signed main(){
//	freopen("Aruba.in","r",stdin);
//	freopen("Aruba.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>s;s='!'+s;n*=3;
	for(int i=1;i<siz(s);i++)mp[s[i]].updata(i);
	// for(int k=1,p1=1;k<=n/3;k++){
		// while(s[p1]=='~')p1++;
		// ans[p1]=k;mp[s[p1]].updata(p1,-1);
		// int p2=p1;
		// for(int i=1<<std::__lg(n);i;i>>=1)
		// 	if(p2+i<=n&&mp[find(s[p1]).first].query(p1,p2+i)+mp[find(s[p1]).second].query(p1,p2+i)==0)p2+=i;
		// ans[++p2]=k;mp[s[p2]].updata(p2,-1);
		// char c3=find(s[p1])&find(s[p2]);int p3=p2;
		// for(int i=1<<std::__lg(n);i;i>>=1)
		// 	if(p3+i<=n&&mp[c3].query(p2,p3+i)==0)p3+=i;
		// ans[++p3]=k;mp[s[p3]].updata(p3,-1);
		// s[p1]=s[p2]=s[p3]='~';
	for(int k=1,l=1,r=n;k<=n;){
		l=std::min({next(0,'A'),next(0,'C'),next(0,'B')});
		r=std::max(prev(n+1,find(s[l]).first),prev(n+1,find(s[l]).second));
		// cout<<k<<' '<<l<<' '<<r<<'\n';
		// cout<<prev(n+1,find(s[l]).first)<<' '<<prev(n+1,find(s[l]).second)<<'\n';
		char c1=s[l],c3=s[r],c2=find(c1)&find(c3);
		// cout<<c1<<' '<<c2<<' '<<c3<<'\n';
		int cnt=1;
		while(next(l,c1)<prev(r,c3)&&mp[c2].query(next(l,c1),prev(r,c3))>=cnt+1)
			mp[c1].updata(l,-1),mp[c3].updata(r,-1),ans[l]=ans[r]=k,s[l]=s[r]='~',l=next(l,c1),r=prev(r,c3),cnt++;
		mp[c1].updata(l,-1),mp[c3].updata(r,-1),ans[l]=ans[r]=k,s[l]=s[r]='~';
		// cout<<"!!!!"<<l<<' '<<r<<'\n';
		int kkk=k+3*cnt;
		// cout<<"------------\n";
		// for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
		// cout<<"\n==============\n";
		// cout<<s<<'\n';
		// for(int i=1;i<=n;i++){cout<<mp['A'].query(i,i)<<' ';}cout<<'\n';
		// for(int i=1;i<=n;i++){cout<<mp['C'].query(i,i)<<' ';}cout<<'\n';
		// for(int i=1;i<=n;i++){cout<<mp['B'].query(i,i)<<' ';}cout<<'\n';
		while(cnt--){
			// r=prev(r,c2),cout<<"del"<<r<<'\n',s[r]='~',mp[c2].updata(r,-1),ans[r]=k;
			r=prev(r,c2),s[r]='~',mp[c2].updata(r,-1),ans[r]=k;
			// for(int i=1;i<=n;i++){cout<<mp['B'].query(i,i)<<' ';}cout<<'\n';
		}
		k=kkk;
		// cout<<"------------\n";
		// for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
		// cout<<"\n==============\n";
		// cout<<s<<'\n';
		// for(int i=1;i<=n;i++){cout<<mp['A'].query(i,i)<<' ';}cout<<'\n';
		// for(int i=1;i<=n;i++){cout<<mp['C'].query(i,i)<<' ';}cout<<'\n';
		// for(int i=1;i<=n;i++){cout<<mp['B'].query(i,i)<<' ';}cout<<'\n';
	}
	std::basic_string<int>b;
	for(int i=1;i<=n;i++)b+=ans[i];
	std::sort(all(b));b.erase(std::unique(all(b)),b.end());
	for(int i=1;i<=n;i++)cout<<std::lower_bound(b.begin(),b.end(),ans[i])-b.begin()+1;
	return 0;
}