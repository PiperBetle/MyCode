#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[1000007],q[1000007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int type;
	int left,right;
	
	cin>>n>>type;
	for(i=1;i<=n;i++)
		cin>>a[i];
	
	memset(q,0,sizeof q);
	left=right=1;
	q[1]=1;
	for(i=1;i<=n;i++)
	{
		while(left<=right&&i-q[left]>=k)
			left++;
		while(left<=right&&a[q[right]]>a[i])
			right--;
		q[++right]=i;
		if(i>=k)cout<<a[q[left]]<<" ";
	}
	cout<<'\n';
	//* min
	memset(q,0,sizeof q);
	left=right=1;
	q[1]=1;
	for(i=1;i<=n;i++)
	{
		while(left<=right&&i-q[left]>=k)
			left++;
		while(left<=right&&a[q[right]]<a[i])
			right--;
		q[++right]=i;
		if(i>=k)cout<<a[q[left]]<<" ";
	}
	cout<<'\n';
	//* max
	return 0;
}