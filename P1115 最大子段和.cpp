#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main()
{
	int a[200005],c[200005],i,j,k,m,n,t,len,ans=-999999;
	
	cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        c[i]=max(c[i-1]+a[i],a[i]);
        ans=max(ans,c[i]);
    }
    cout<<ans;
    
	
	return 0;
}
