#include<iostream>
#include<cstdio>
using namespace std;
int a[1007],b[1007];
int abs(int _x){if(_x>0)return _x;else return -_x;}
int main()
{
//	freopen("rotation.in","r",stdin);freopen("rotation.out","w",stdout);
	int i,j,k,n,m,t,T;
	scanf("%d",&n);
	for(i=1;i<n;i++){cin>>t>>T>>m;a[t]=1-m;}
	b[1]=1;
	for(i=2;i<=n;i++)b[i]=abs(a[i-1]-b[i-1]);
	cout<<b[n];
	return 0;
}
