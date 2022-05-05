#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
std::string a,b,x,y;
int la,lb;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>a>>b;
	la=a.length();lb=b.length();
	for(i=min(la,lb);i>=1;i--)
	{
		x=a.substr(0,i);
		y=b.substr(lb-i,i);
		if(x==y)
			return cout<<i<<'\n',0;
		x=a.substr(la-i,i);
		y=b.substr(0,i);
		if(x==y)
			return cout<<i<<'\n',0;
	}
	cout<<"0\n";
	
	return 0;
}