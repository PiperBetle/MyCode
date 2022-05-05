#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[1000007],f[1000007],q[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int left,right;

	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cin>>T;
	while(T--)
	{
		cin>>k;
		left=right=1;
		q[1]=1;
		for(i=2;i<=n;i++)
		{
			while(left<=right&&i-q[left]>k)
				left++;
			f[i]=f[q[left]]+(a[q[left]]<=a[i]);
			while(left<=right&&(f[q[right]]>f[i]||(f[q[right]]==f[i]&&a[q[right]]<=a[i])))
				right--;
			q[++right]=i;
		}
		cout<<f[n]<<'\n';
	}
	
    return 0;
}