#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
inline int MAX(int x,int y){return x>y?x:y;}
inline int MIN(int x,int y){return x<y?x:y;}
inline int ABS(int x){return x>0?x:-x;}
using namespace std;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int left=1,right=1000000000,mid;
	
	while(left<=right)
	{
		mid=(left+right)>>1;
		cout<<mid<<endl;
		cin>>t;
		if(t==-1)left=mid+1;
		else if(t==1)right=mid-1;
		else return 0;
	}
	
	return 0;
}