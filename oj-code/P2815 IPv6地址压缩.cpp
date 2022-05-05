#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int a[11],sum[11];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int l=0,r=0;
	
	scanf("%x:%x:%x:%x:%x:%x:%x:%x",a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8);
	for(i=1;i<=8;i++)sum[i]=sum[i-1]+(a[i]==0);
	for(i=1;i<8;i++)for(j=i;j<=8;j++)
		if(sum[j]-sum[i-1]==j-i+1&&sum[j]-sum[i-1]>sum[r]-sum[l-1])l=i,r=j;
	if(l==0&&r==0){printf("%x",a[1]);for(i=2;i<=8;i++)printf(":%x",a[i]);return 0;}
	if(l==1)putchar(':');
	for(i=1;i<l;i++)printf("%x:",a[i]);
	for(i=r+1;i<=8;i++)printf(":%x",a[i]);
	if(r==8)putchar(':');
	
	return 0;
}