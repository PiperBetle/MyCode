#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define siz(x) (int)(x).size()
using std::cin;using std::cout;
constexpr int kN=1<<20,kM=27;
inline auto get_z(const std::string &a){
	std::basic_string<int>z(siz(a),0);
	z[0]=siz(a);
	for(int i=1,l=-1,r=-1;i<siz(a);i++){
		if(i<=r)z[i]=std::min(z[i-l],r-i+1);
		while(z[i]+i<siz(a)&&a[z[i]+i]==a[z[i]])z[i]++;
		if(z[i]+i-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}
std::string a;
std::basic_string<int>z;
int pre[kM],suf[kM],tr[kM];
void updata(int x){for(;x<kM;x+=x&-x)tr[x]++;}
int query(int x){int k=0;for(;x;x-=x&-x)k+=tr[x];return k;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	a.reserve(kN),z.reserve(kN);
	int T;cin>>T;while(T--){
		cin>>a;z=get_z(a);
		memset(pre,0,sizeof pre);
		memset(suf,0,sizeof suf);
		memset(tr,0,sizeof tr);
		for(int i=0;i<siz(z);i++)if(i+z[i]==siz(z))z[i]--;
		for(int i=0;i<siz(a);i++)suf[a[i]-'a'+1]++;
		for(int i=1;i<=26;i++)*suf+=(suf[i]&1);
		int sum=*suf;long long ans=0;
		for(int i=0;i<siz(a);i++){
			if(suf[a[i]-'a'+1]--&1)--*suf;else ++*suf;
			if(pre[a[i]-'a'+1]++&1)--*pre;else ++*pre;
			if(i!=0&&i!=siz(a)-1){
				int t=z[i+1]/(i+1)+1;
				ans+=1ll*(t/2)*query(sum+1)+1ll*(t-t/2)*query(*suf+1);
			}
			updata(*pre+1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}