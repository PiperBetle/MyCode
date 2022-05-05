#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int f[5000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
struct edge{int u,v,t;bool operator<(const edge &n)const{return t<n.t;}}a[80000007];
signed main()
{
//	freopen("seq.in","r",stdin);
//	freopen("seq.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
    int ans=0,cnt=0,L,R;
    cin>>L>>R;
    for(int i=1;i<=R;i++)f[i]=i;
    for(int i=R;i>=1;i--){
        for(int j=1,lst=0;j<=R;j++){
        	if(i*j>R)break;
	        if(i*j<L)continue;
        	if(!lst)lst=j;
        	a[++cnt].u=i*j,a[cnt].v=lst*i,a[cnt].t=i*j*lst;
        }
    }
    std::sort(a+1,a+cnt+1);
    for(int tmp=0;;){   
        for(int i=1;i<=cnt;i++){
            int fx=find(a[i].u),fy=find(a[i].v);
            if(fx!=fy)f[fx]=fy,tmp++,ans+=a[i].t;
        }
        if(tmp==R-L)return cout<<ans,0;
    }
}
