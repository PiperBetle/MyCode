#include <cstdio>
using namespace std;
const int N=1e7+7;
int prime[N], least_factor[N];
bool p[N],vis[N];
void st(int cnt){
	for(int i=2;i<N;i++){
		vis[i]=false;
	}
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x;
}
int main()
{
	int t,cnt;
	scanf("%d",&t);
	p[0]=p[1]=1;
	least_factor[1]=1;
	for(int i=2;i<N;i++)
	{
		if(!p[i]){
			prime[++cnt]=i;
			least_factor[i]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<N;j++)
		{
			int t=i*prime[j];
			p[t]=1;
			least_factor[t]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
	for(int i=1;i<=t;i++){
		int n,ans;
		scanf("%d",&n);
		st(cnt);
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			while(x>1)
			{
				vis[least_factor[x]]=1;
				x/=least_factor[x];
			}
		}
		for(int j=1;j<=cnt;j++){
			if(!vis[prime[j]])
			{
				ans=prime[j];
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
