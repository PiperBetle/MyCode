#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,t;
int a[37],sum[37];
bool dfs(int now,int _1,int _2,int _3)
{
	if(_1>m/4)return 0;
	if(_2>m/4)return 0;
	if(_3>m/4)return 0;
	if(_1+_2+_3>3*m/4)return 0;
	if(now==n+1)
	{
//		cout<<_1<<" "<<_2<<" "<<_3<<" "<<m-_1-_2-_3<<endl;
		if((_1==_2)&&(_1==_3)&&(m-_1-_2-_3==_1))
			return 1;
		return 0;
	}
	return dfs(now+1,_1+a[now],_2,_3)||dfs(now+1,_1,_2+a[now],_3)||dfs(now+1,_1,_2,_3+a[now])||dfs(now+1,_1,_2,_3);
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k,T;
	
	cin>>T;
	while(T--)
	{
		m=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			m+=a[i];
		}
		if(m%4!=0)cout<<"no\n";
		else
		{
			if(dfs(1,0,0,0))cout<<"yes\n";
			else cout<<"no\n";
		}
	}
	
	return 0;
}

