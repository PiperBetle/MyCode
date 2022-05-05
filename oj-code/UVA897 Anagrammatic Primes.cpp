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
int a[]={0,2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	while(cin>>n)
	{
		if(!n)return 0;
		if(n>=991||n==7||n==8||n==9||n==97||n==98||n==99){cout<<"0\n";continue;}
		for(i=1;;i++)if(a[i]>n){cout<<a[i]<<'\n';break;}
	}
	
	return 0;
}
