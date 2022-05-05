#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
using namespace std;
bool pr[10000007]={0,1};
int pt[10000007],len;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	for(i=2;i<=10000000;i++)
	{
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=10000000;j++)
		{
			pr[i*pt[j]]=1;
			if(i%pt[j]==0)break;
		} 
	}
	while(cin>>n)
	{
		if(n<8){cout<<"Impossible.\n";continue;}
		cout<<"2 "<<(2+(n&1))<<' ';
		n=n-4-(n&1);
		for(i=1;;i++)if(!pr[n-pt[i]]){cout<<pt[i]<<' '<<n-pt[i]<<'\n';break;}
	}
	
	return 0;
}
