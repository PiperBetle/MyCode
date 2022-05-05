#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using std::cin;using std::cout;
std::string s,a[10007];
int same[10007][507],cnt[10007][507],f[10007];
signed main(){
//	freopen("flower.in","r",stdin);
//	freopen("flower.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,l;cin>>n>>l>>s;s=" "+s;
	memset(same,0x3f,sizeof same);
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i]=" "+a[i];
		for(int j=1;j<=l;j++){
			if(s[j]!=a[i].back()){same[i][j]=same[i][j-1];cnt[i][j]=cnt[i][j-1]+1;continue;}
			int p1=j,p2=a[i].length()-1;
			for(;p1&&p2;p1--)if(s[p1]==a[i][p2])p2--;else cnt[i][j]++;
			if(!p2)same[i][j]=p1;
		}
	}
	for(int j=1;j<=l;j++){
		f[j]=j;
		for(int i=1;i<=n;i++){
			if(same[i][j]==0x3f3f3f3f)continue;
			f[j]=std::min(f[same[i][j]]+cnt[i][j],f[j]);
		}
	}
	cout<<f[l];
	return 0;
}