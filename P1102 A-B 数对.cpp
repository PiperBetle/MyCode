#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
using namespace std;
int main()
{
	long long a[200001]={0},i,j,k,m,n,t,len,ans=0,c;
	map<long long,long long> b;
	
	cin>>n>>c;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	for(i=1;i<=n;i++)ans+=b[a[i]-c];
	cout<<ans;
	
	return 0;
}
