#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct sth
{
	int left,right;
};
sth a[1000001];
int cmp(sth x,sth y)
{
	return x.right<y.right;
}
int main()
{
	int i,j,k;
	int n,T;
	int ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].left>>a[i].right;
	sort(a+1,a+1+n,cmp);
//	cout<<endl;
//	for(i=1;i<=n;i++)cout<<a[i].left<<" "<<a[i].right<<endl;
	int st=-1;
	for(i=1;i<=n;i++)
		if(a[i].left>=st)
		{
			ans++;
			st=a[i].right;
		}
	cout<<ans;
	
	return 0;
}
