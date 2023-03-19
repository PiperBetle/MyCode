#include<iostream>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int a[10001];
int n,m,ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x]++;
        a[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]%2==1)
              ans++;
    }
    if(ans)
       cout<<ans/2;
    else
       cout<<ans+1;
    return 0;
}
