#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,m;
int a[1000007];
inline bool check(int x)
{
    int sum=0,tot=0;
    for(int i=1;i<=n;i++)
    {
        if(sum+a[i]<=x)
            sum+=a[i];
        else
        {
            sum=a[i];
            tot++;
        }
    }
    return tot>=m;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
    int left=0,right=0,mid;
	
	cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        left=max(left,a[i]);
        right+=a[i];
    }
    while(left<=right)
    {
        mid=(left+right)>>1;
        if(check(mid))
            left=mid+1;
        else
            right=mid-1;
    }
    cout<<left;
	
    return 0;
}