#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
std::string s1,s2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		int n,a,b,c,cnt=0;cin>>n>>a>>b>>c>>s1;
		s2.resize(n);std::fill(s2.begin(),s2.end(),' ');
		for(int i=0;i<n;i++)switch(s1[i]){
		case 'R':if(b)b--,s2[i]='P',cnt++;break;
		case 'P':if(c)c--,s2[i]='S',cnt++;break;
		case 'S':if(a)a--,s2[i]='R',cnt++;break;
		}
		if(cnt*2>=n){
			for(int i=0;i<n;i++)if(s2[i]==' '){
				if(a)a--,s2[i]='R';
				else if(b)b--,s2[i]='P';
				else s2[i]='S';
			}
			cout<<"YES\n"<<s2<<'\n';
		}else cout<<"NO\n";
	}
	return 0;
}