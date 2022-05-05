#include<iostream>
#include<cstdio>
#include<algorithm>
#define MOD 1000000009
#define int long long
using std::cin;using std::cout;
int f[10007][10][10],pt[10007],len;
bool pr[10007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,ans=0;
	cin>>n;
	if(n<=2)return cout<<0,0;
	for(pr[0]=pr[1]=0,i=2;i<=10000;i++){
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=10000;j++){
			pr[i*pt[j]]=1;
			if(!(i%pt[j]))break;
		}
	}
	for(i=0;i<=9;i++)for(j=0;j<=9;j++)f[2][i][j]=1;
	for(i=3;i<=n;i++)for(int n1=1;n1<=9;n1++)for(int n2=0;n2<=9;n2++)for(int n3=0;n3<=9;n3++)
		if(!pr[100*n1+10*n2+n3])(f[i][n1][n2]+=f[i-1][n2][n3])%=MOD;
	for(i=0;i<=9;i++)for(j=0;j<=9;j++)(ans+=f[n][i][j])%=MOD;
	cout<<ans;
	return 0;
}