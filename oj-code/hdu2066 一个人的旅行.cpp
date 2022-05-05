#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int visit[1007],dis[1007],a[1007][1007],p[1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    std::ios::sync_with_stdio(false);
    int i,j,k;
    int n,m,q;
    int x,y,t;
    int T,S,D;
    
    while(cin>>T>>S>>D)
    {
        for(i=0;i<=1006;i++)
        {
            dis[i]=1e9;
            visit[i]=1;
            for(j=0;j<=1006;j++)a[i][j]=1e9;
            a[i][i]=0;
        }
        int num=-1;
        for(i=0;i<T;i++)
        {
            cin>>x>>y>>t;
            a[x][y]=min(t,a[x][y]);
            a[y][x]=min(t,a[y][x]);
            num=max(num,max(x,y));
        }
        for(i=0;i<S;i++)
        {
        	cin>>t;
        	a[0][t]=0;
		}
		for(i=0;i<D;i++)
			cin>>p[i];
        dis[0]=0;
        for(i=0;i<=num;i++)
        {
            int ans=1e9;
            for(j=0;j<=num;j++)
                if((visit[j])&&(dis[j]<ans))
                {
                    ans=dis[j];
                    q=j;
                }
            visit[q]=0;
            for(j=0;j<=num;j++)
                if((visit[j])&&(dis[j]>dis[q]+a[q][j]))
                    dis[j]=dis[q]+a[q][j];
        }
        int ans=1e9;
        for(i=0;i<D;i++)ans=min(ans,dis[p[i]]);
        cout<<ans<<"\n";
    }
    
    return 0;
}
