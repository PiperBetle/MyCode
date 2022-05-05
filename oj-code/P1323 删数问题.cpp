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
int a[30007];
std::string s;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;

	cin>>n>>k;
	int _1=1,_2=1;a[1]=1;
	for(i=2;i<=30000;i++)
	{
		a[i]=min((a[_1]<<1)+1,(a[_2]<<2)+5);
		if((a[_1]<<1)+1==a[i])_1++;else _2++;
		if(a[i]==a[i-1])i--;
	}
	s="";
	for(i=1;i<=n;i++)s+=std::to_string(a[i]);
	cout<<s<<'\n';int len=s.length();
	for(;k>=1;k--,len--)for(i=0;i<len;i++)
		if(s[i]<s[i+1]){s.erase(i,1);break;}
	for(i=0;i<len;i++)cout<<s[i];

	return 0;
}