#include<cstring>
#include<cstdio>
#include<algorithm>
constexpr unsigned long long MOD1=998244353,MOD2=19260817;
char a[2007][2007],b[2007][2007];
unsigned long long m1[20000007],m2[20000007],s1[2007][2007],s2[2007][2007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for(int i=m1[0]=m2[0]=1;i<20000007;i++)m1[i]=m1[i-1]*MOD1,m2[i]=m2[i-1]*MOD2;
	int T;scanf("%d",&T);while(T--){
		int x1,y1;scanf("%d%d",&x1,&y1);
		for(int i=0;i<x1;i++)scanf("%s",a[i]);
		for(int i=0;i<x1;i++)for(int j=0;j<y1;j++)s1[i+1][j+1]=s1[i][j+1]*MOD1+s1[i+1][j]*MOD2-s1[i][j]*MOD1*MOD2+a[i][j];
		int x2,y2;scanf("%d%d",&x2,&y2);
		for(int i=0;i<x2;i++)scanf("%s",b[i]);
		for(int i=0;i<x2;i++)for(int j=0;j<y2;j++)s2[i+1][j+1]=s2[i][j+1]*MOD1+s2[i+1][j]*MOD2-s2[i][j]*MOD1*MOD2+b[i][j];
		int cnt=0;
		for(int i=0;i<x1-x2+1;i++)for(int j=0;j<y1-y2+1;j++)
			if(s1[i+x2][j+y2]-s1[i][j+y2]*m1[x2]-s1[i+x2][j]*m2[y2]+s1[i][j]*m1[x2]*m2[y2]==s2[x2][y2])cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}