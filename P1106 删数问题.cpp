#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
std::string s;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t=1;
	
	cin>>s>>k;
	int len=s.length();
	if(len==k)return cout<<0,0;
	for(;k>=1;k--,len--)for(i=0;i<len;i++)
	{
		if(s[i]<=s[i+1])continue;
		for(;i<len-1;i++)s[i]=s[i+1];
		break;
	}
	for(i=0;i<len;i++)if(s[i]!='0')break;
	for(;i<len;i++)t=0,cout<<s[i];
	if(t)cout<<0;
	
	return 0;
}