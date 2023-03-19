#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using std::cin;using std::cout;
inline int f(char c){if(c=='A')return 1;if(c=='N')return 2;if(c=='O')return 3;if(c=='T')return 4;return EOF;}
std::string s,ans,now;
int a[100007],t[100007];
long long cnt;
void ms(int l,int r)
{
	if(l==r)return;
	int m=(l+r)>>1;
	ms(l,m);ms(m+1,r);
	int p=l,i=l,j=m+1;
	while(i<=m&&j<=r)
		if(a[i]>a[j])cnt+=m-i+1,t[p++]=a[j++];
		else t[p++]=a[i++];
	while(i<=m)t[p++]=a[i++];
	while(j<=r)t[p++]=a[j++];
	for(i=l;i<=r;i++)a[i]=t[i];
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int T;cin>>T;while(T--){
		char ch[]={'A','N','O','T'};
		cin>>s;ans.clear();
		long long max=-0x3f3f3f3f3f3f3f3f;
		std::vector<int>c[5];
		for(size_t i=0;i<s.length();i++)c[f(s[i])].emplace_back(i+1);
		do{
			int la=0;now.clear();cnt=0ll;
			for(int i=0;i<4;i++)for(auto it:c[f(ch[i])])
				now+=ch[i],a[++la]=it;
			ms(1,la);
			if(cnt>max)max=cnt,ans=now;
		}while(std::next_permutation(ch,ch+4));
		cout<<ans<<'\n';
	}
	return 0;
}