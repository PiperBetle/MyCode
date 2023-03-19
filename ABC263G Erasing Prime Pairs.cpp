#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=101,inf=0x3f3f3f3f;
loli n,m,s,t,ans,vis[N*2],pre[N*2],inc[N*2],v[N*2][N*2],a[N*2],A[N*2],b[N*2],B[N*2],ji,ou,cnt;
loli hd[N*2],nxt[N*N*2],vl[N*N*2],to[N*N*2],cnt=1;
std::queue<loli>q;
void add(loli x,loli y,loli z){
	nxt[++cnt]=hd[x];hd[x]=cnt;to[cnt]=y;vl[cnt]=z;
	nxt[++cnt]=hd[y];hd[y]=cnt;to[cnt]=x;vl[cnt]=0;
}
bool bfs(){    
   memset(vis,0,sizeof(vis));vis[s]=1;
   while(!q.empty())q.pop();q.push(s);
   inc[s]=inf;
   while(!q.empty()){
       int x=q.front();q.pop();
       for(int i=hd[x],y;i;i=nxt[i])
        if(vl[i]&&(!vis[y=to[i]])){
           	inc[y]=std::min(inc[x],vl[i]);
           	pre[y]=i;q.push(y);vis[y]=1;
           	if(y==t)return true;
       	}
   }
   return false;
}
inline bool isprime(loli x){
	for(int i=2;i*i<=x;++i)if(x%i==0)return 0;
	return 1;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;s=1;t=n+2;
	for(int i=1,x,y;i<=n;++i){
		cin>>x>>y;
		if(x&1)a[++ji]=x,A[ji]=y;else b[++ou]=x,B[ou]=y;
		if(x==1)cnt=ji;
	}
	for(int i=1;i<=ou;++i)add(s,i+1,B[i]);
	for(int i=1;i<=ji;++i)add(i+ou+1,t,A[i]);
	for(int i=1;i<=ji;++i)if(i!=cnt)for(int j=1;j<=ou;++j)
	if(isprime(a[i]+b[j]))add(j+1,i+1+ou,inf);
	while(bfs()){
		for(int i=t,j;i!=s;i=to[j^1]){
			j=pre[i];vl[j]-=inc[t];
			vl[j^1]+=inc[t];
		}
		ans+=inc[t];
	}
	if(cnt){
		for(int j=1;j<=ou;++j)if(isprime(a[cnt]+b[j]))add(j+1,cnt+1+ou,inf);
		while(bfs()){
			for(int i=t,j;i!=s;i=to[j^1]){
				j=pre[i];vl[j]-=inc[t];
				vl[j^1]+=inc[t];
			}
			ans+=inc[t];
		}
		for(int i=hd[cnt+ou+1];i;i=nxt[i])if(to[i]==t)ans+=vl[i]/2;
	}
	cout<<ans;
	return 0;
}