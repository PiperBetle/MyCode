#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<deque>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=3e5+1;
std::deque<int>q;
int n,cnt[N];
bool res[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		memset(cnt+1,0,sizeof(int)*n);
		memset(res+1,0,sizeof(bool)*n);
		q.clear();
		for(int i=1,x;i<=n;i++)cin>>x,q.push_back(x),cnt[x]++;
		for(int i=1;i<=n;i++){
			if(!cnt[i])break;
			res[i]=true;
			if(cnt[i]>1)break;
			if(q.front()==i)q.pop_front();
			else if(q.back()==i)q.pop_back();
			else break;
		}
		res[n]=!std::count(cnt+1,cnt+1+n,false);
		for(int i=n;i>=1;i--)cout<<res[i];
		cout<<'\n';
	}
	return 0;
}