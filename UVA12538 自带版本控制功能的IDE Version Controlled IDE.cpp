#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ext/rope>
using std::cin;using std::cout;
namespace cxx=__gnu_cxx;
constexpr int kN=5e4+1;
cxx::crope a,b[kN];
int n,len,cnt;
char s[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;for(int v,p,c;T--;)switch(cin>>p,p){
	case 1:cin>>p>>s;p-=cnt;a.insert(p,s);b[++len]=a;break;
	case 2:cin>>p>>c;p-=cnt,c-=cnt;a.erase(p-1,c);b[++len]=a;break;
	case 3:cin>>v>>p>>c;v-=cnt,p-=cnt,c-=cnt;auto ans=b[v].substr(p-1,c);cnt+=std::count(ans.begin(),ans.end(),'c');cout<<ans<<'\n';break;
	}
	return 0;
}