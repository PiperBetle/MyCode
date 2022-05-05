#include<iostream>
using namespace std;
struct people{
    bool c;
    string name;
}f[200000];
int ans=1;
int main()
{
//	freopen("toy.in","r",stdin);
//	freopen("toy.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>f[i].c>>f[i].name;
    int k;
    int x;
    for(int i=1;i<=m;++i)
    {
        cin>>k>>x;
        if(k!=f[ans].c)    k=1;
        else k=-1;
        ans+=x*k;
        while(ans<=0||ans>n)
        {
            if(ans<=0)    ans+=n;
            if(ans>n)    ans-=n;
        }
    }
    cout<<f[ans].name;
    return 0;
}
