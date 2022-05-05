#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
std::string s1,s2;
std::map<std::pair<char,char>,int>mp;
using std::cin;using std::cout;
using std::max;
int f[3007][3007][3];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,A,B;
	cin>>s1>>s2;
	cin>>mp[{'A','A'}]>>mp[{'A','T'}]>>mp[{'A','G'}]>>mp[{'A','C'}];
	cin>>mp[{'T','A'}]>>mp[{'T','T'}]>>mp[{'T','G'}]>>mp[{'T','C'}];
	cin>>mp[{'G','A'}]>>mp[{'G','T'}]>>mp[{'G','G'}]>>mp[{'G','C'}];
	cin>>mp[{'C','A'}]>>mp[{'C','T'}]>>mp[{'C','G'}]>>mp[{'C','C'}];
	cin>>A>>B;
	s1=" "+s1;s2=" "+s2;
	int l1=s1.length(),l2=s2.length();
	memset(f,-0x3f,sizeof f);f[0][0][0]=0;
	for(i=0;i<=l1;i++)for(j=0;j<=l2;j++){
		if(i>0&&j>0)f[i][j][0]=max({f[i-1][j-1][0],f[i-1][j-1][1],f[i-1][j-1][2]})+mp[{s1[i],s2[j]}];
		if(i>0)f[i][j][1]=max({f[i-1][j][0]-A,f[i-1][j][1]-B,f[i-1][j][2]-A});
		if(j>0)f[i][j][2]=max({f[i][j-1][0]-A,f[i][j-1][1]-A,f[i][j-1][2]-B});
	}
	cout<<max({f[l1][l2][0],f[l1][l2][1],f[l1][l2][2]});
	return 0;
}