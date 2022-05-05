#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int f[1007],de,n;
bool dfs(int step,int power)
{
	if(step>de||power<=0||(power<<(de-step))<n)
		return 0;
	if(power==n||(power<<(de-step))==n)
		return 1;
	f[step]=power;
	for(int i=0;i<=step;i++)
	{
		if(dfs(step+1,power+f[i])) 
			return 1;
		if(dfs(step+1,power-f[i]))
			return 1;
	}
	return 0;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	while(cin>>n)
	{
		if(!n)return 0;
		if(n==1){cout<<"0\n";continue;}
		de=0;f[0]=1;
		while(!dfs(0,1))
			de++;
		cout<<de<<'\n';
	}
	
	return 0;
}