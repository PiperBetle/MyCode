#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
int w[20001],f[20001];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int v,n;
	
	cin>>v>>n;
	for(i=1;i<=n;i++)cin>>w[i];
	for(i=1;i<=n;i++)
    	for(j=v;j>=w[i];j--)
    		f[j]=max(f[j],f[j-w[i]]+w[i]);
    cout<<v-f[v];
	
	return 0;
}
