//P6824
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,k,a,i,f[1050005];
inline int B(int a,int b) { return a>b?a:b; }
inline void Add()
{	int sum,A,K,i;
	for (i=20;i;i--) if ((k&(1<<i-1))||(a&(1<<i-1))) break;
	for (sum=0;i;i--)
	{	sum<<=1;
		A=(a>>i-1)&1;
		K=(k>>i-1)&1;
		if (K) f[sum+A<<i-1]++,f[sum+A+1<<i-1]--;
		sum+=(K)?(A^1):A;
		}
	f[sum]++,f[sum+1]--;
}
int main()
{	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) scanf("%d",&a),Add();
	for (a=i=k=0;i<1<<20;i++) k+=f[i],a=B(a,k);
	printf("%d",a);
	return 0;
}
