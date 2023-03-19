#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x<y?y:x;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return 0<x?x:-x;}
struct ex{int type,data;}a[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,w;
	int n,m,t;
	double k,c,ans=0;
	
	scanf("%d%lf%lf%d",&n,&k,&c,&w);
	k=1-0.01*k;c=1+0.01*c;
	for(i=1;i<=n;i++)cin>>a[i].type>>a[i].data;
	for(i=n;i>=1;i--)
		if(a[i].type==1)ans=max(ans,ans*k+a[i].data);
		else ans=max(ans,ans*c-a[i].data);
	printf("%.2lf",ans*w);
	
	return 0;
}