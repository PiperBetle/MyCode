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
struct qw
{
	int x,y,z;
};
qw edge[200007];
int f[200007];
bool cmp(qw a,qw b){return a.z<b.z;}
int find(int x){return x==f[x]? x:f[x]=find(f[x]);}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int n,m,ans=0,cnt=0;
	int i,j,k;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=m;i++)cin>>edge[i].x>>edge[i].y>>edge[i].z;
	sort(edge+1,edge+1+m,cmp);
	for(i=1;i<=m;i++)
    {
        int p1=find(edge[i].x),p2=find(edge[i].y);
        if(p1==p2)continue;
        ans+=edge[i].z;
        f[p2]=p1;
        cnt++;
        if(cnt==n-1)break;
    }
	cout<<ans;
	
	return 0;
}
