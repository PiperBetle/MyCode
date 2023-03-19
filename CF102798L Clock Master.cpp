#include<cstdio>
#include<cmath>
double f[100007],lg[100007];
bool pr[100007];
int pt[100007],l;
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	int i,j,k,T,n;
	for(i=2;i<=100000;i++){
		if(!pr[i])pt[++l]=i;
		lg[i]=log(i);
		for(j=1;j<=l&&i*pt[j]<=100000;j++){
			pr[i*pt[j]]=true;
			if(i%pt[j]==0)break;
		}
	}
	scanf("%d",&T);
	for(i=2*sqrt(l);i>=1;i--)for(j=100000;j>=pt[i];j--)for(k=pt[i];k<=j;k*=pt[i])
		f[j]=std::max(f[j],f[j-k]+lg[k]);
	while(T--)scanf("%d",&n),printf("%.7lf\n",f[n]);
	return 0;
}