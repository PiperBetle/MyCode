#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int a[1007],b[1007];
int s[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	int na,nb;
	int ans_a=0,ans_b=0;
	
	cin>>n>>na>>nb;
	for(i=0;i<na;i++)cin>>a[i];
	for(i=0;i<nb;i++)cin>>b[i];
	for(i=0;i<n;i++)
	{
		ans_a+=s[a[i%na]][b[i%nb]];
		ans_b+=s[b[i%nb]][a[i%na]];
	}
	cout<<ans_a<<" "<<ans_b;
	
    return 0;
}
