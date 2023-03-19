#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int max(int x,int y)
{
	if(x>y)return x;
	else return y;
}
int ex(int k)
{
	char c;
	while(cin>>c)
	{
		if(c=='a')k++;
		if(c=='(')k+=ex(0);
		if(c=='|')return max(k,ex(0));
		if(c==')')return k;
	}
	return k;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cout<<ex(0);
	
	return 0;
}
