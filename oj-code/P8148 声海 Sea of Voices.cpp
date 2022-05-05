#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x<y?y:x;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return 0<x?x:-x;}
int a[4000007],b[2007];
std::priority_queue<int,std::vector<int>,std::greater<int> >q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j=1,k;
	int n,m,s;
	
	cin>>n;m=n*(n+1)>>1;
	for(i=1;i<=m;i++)cin>>a[i];
	std::sort(a+1,a+1+m);
	for(i=1;i<=n;i++)
	{
		while(!q.empty()&&q.top()==a[j])q.pop(),j++;
		cout<<(b[i]=a[j])<<' ';s=0;
		for(k=i;k;k--)q.push(s+=b[k]);
	}
	
	return 0;
}