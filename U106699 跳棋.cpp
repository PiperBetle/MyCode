#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int f[20005];
int a[20005];
void dfs(int x,int s,int txn)
{
    if(s>ans)
    	return;
    if(x==n)
	{
    	ans=min(ans,s);
    	return;
    }
    if(x+txn+1<=n)
    	dfs(x+txn+1,s+a[x+txn+1],txn+1);
    if(x-txn>=1)
		dfs(x-txn,s+a[x-txn],txn);
}
int main() 
{
   cin>>n;
   ans=1e9;
   for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
   dfs(1,0,0);
   cout<<ans;
   return 0;
}
