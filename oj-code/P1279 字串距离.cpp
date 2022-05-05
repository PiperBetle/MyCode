#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int f[2007][2007];
std::string s1,s2;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;

	cin>>s1>>s2>>k;
	int l1=s1.length(),l2=s2.length();
	f[0][0]=0;
	for(i=1;i<=l1;i++)f[i][0]=i*k;
	for(j=1;j<=l2;j++)f[0][j]=j*k;
	for(i=1;i<=l1;i++)for(j=1;j<=l2;j++)
		f[i][j]=min(min(f[i-1][j],f[i][j-1])+k,f[i-1][j-1]+abs(s1[i-1]-s2[j-1]));
	cout<<f[l1][l2];

	return 0;
}