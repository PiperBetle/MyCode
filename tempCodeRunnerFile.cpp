#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=25;
int T;
 int l,r;
int A[N];

int f[N][(1<<10)+5][(1<<10)+5];

inline int dfs(int k,int now,int Now,bool Max,bool zero)
{
    if(!k)
    {
        for(int i=0;i<=9;i++)
            if(Now&(1<<i))
                if((i&1)^((now&(1<<i))==0))return 0;
        return 1;
    }
    if(!Max&&!zero&&f[k][now][Now]!=-1)return f[k][now][Now];
    int lim=Max?A[k]:9,res=0;
    for(int i=0;i<=lim;i++) 
    {
        if(zero&&i==0)res+=dfs(k-1,0,0,Max&&i==lim,1);
        else res+=dfs(k-1,now^(1<<i),Now|(1<<i),Max&&i==lim,0);
    }
    if(!Max&&!zero)f[k][now][Now]=res;
    return res;
}

inline int solve( int str)
{
    int n=0;
    while(str)A[++n]=str%10,str/=10;
    return dfs(n,0,0,1,1);
}


signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>T;
    memset(f,-1,sizeof(f)); 
    while(T--)
    {
        cin>>l>>r;l--;
        int ans=0;
        ans-=solve(l);
        ans+=solve(r);
        cout<<ans<<'\n';
    }
    return 0;
}
//28825182004525261
//28825182004525261

/*
1
1 10000000000000000000

1
1 100000
*/