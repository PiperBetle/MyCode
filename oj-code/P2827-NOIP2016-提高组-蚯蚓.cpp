#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[10000007],ans1[10000007],ans2[10000007];
queue<int> q1,q2,q3;
signed main()
{
	freopen("earthworm.in","r",stdin);
	freopen("earthworm.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k=0;
	int n,m,q;
	int u,v,t,y=0;
	
	cin>>n>>m>>q>>u>>v>>t;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	for(i=1;i<=n;i++)
		q1.push(a[i]);
	for(i=1;i<=m;i++)
	{
		int t1=-1e17,t2=-1e17,t3=-1e17;
		if(!q1.empty())t1=q1.front();
		if(!q2.empty())t2=q2.front();
		if(!q3.empty())t3=q3.front();
		if(t1>=t2&&t1>=t3)
		{
			q1.pop();
			ans1[i]=t1+y;
		}
		else if(t2>=t1&&t2>=t3)
		{
			q2.pop();
			ans1[i]=t2+y;
		}
		else
		{
			q3.pop();
			ans1[i]=t3+y;
		}
		t1=ans1[i]*u/v;
		t2=ans1[i]-t1;
		y+=q;
		t1-=y;
		t2-=y;
		if(t1<t2)
			swap(t1,t2);
		q2.push(t1);
		q3.push(t2);
	}
	while(!q1.empty()||!q2.empty()||!q3.empty())
	{
		int t1=-1e17,t2=-1e17,t3=-1e17;
		if(!q1.empty())t1=q1.front();
		if(!q2.empty())t2=q2.front();
		if(!q3.empty())t3=q3.front();
		if(t1>=t2&&t1>=t3)
		{
			q1.pop();
			k++;
			ans2[k]=t1+y;
		}
		else if(t2>=t1&&t2>=t3)
		{
			q2.pop();
			k++;
			ans2[k]=t2+y;
		}
		else
		{
			q3.pop();
			k++;
			ans2[k]=t3+y;
		}
	}
	for(i=t;i<=m;i+=t)
		cout<<ans1[i]<<" ";
	cout<<'\n';
	for(i=t;i<=k;i+=t)
		cout<<ans2[i]<<' ';
	cout<<'\n';

	return 0;
}