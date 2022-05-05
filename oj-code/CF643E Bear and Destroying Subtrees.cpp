#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
std::vector<int>s;
constexpr int dep=50;
int n=1,fa[500007];
double f[500007][57];
signed main(){
//	freopen("goodday.in","r",stdin);
//	freopen("goodday.out","w",stdout);
	std::fill_n(&f[1][1],dep,1);
	int T;scanf("%d",&T);for(int t;T--;){
		scanf("%d",&t);
		if(t==1){
			scanf("%d",&t);s.clear();
			fa[++n]=t;t=n;
			std::fill_n(&f[t][1],dep,1);
			for(int i=1;i<=dep+1&&t;i++,t=fa[t])s.emplace_back(t);
			for(int i=s.size()-2;i>0;i--)f[s[i+1]][i+1]/=(f[s[i]][i]+1)/2.0;
			for(int i=0;i<int(s.size())-1;i++)f[s[i+1]][i+1]*=(f[s[i]][i]+1)/2.0;
		}else{
			double ans=dep-1;scanf("%d",&t);
			for(int i=1;i<dep;i++)ans-=f[t][i];
			printf("%.6lf\n",ans);
		}
	}
	return 0;
}