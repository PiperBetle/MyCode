#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
auto MAX(auto x,auto y){return x>y?x:y;}
auto MIN(auto x,auto y){return x<y?x:y;}
int a[100007];
priority_queue<int,vector<int> > max_q;
priority_queue<int,vector<int>,greater<int> > min_q;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,mid;
	
	cin>>n;
	cin>>a[1];
	cout<<a[1];
	mid=a[1];
	for(i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<mid)
			max_q.push(a[i]);
		else
			min_q.push(a[i]);
		if(i&1)
		{
			while(max_q.size()!=min_q.size())
			{
				if(max_q.size()>min_q.size())
				{
					min_q.push(mid);
					mid=max_q.top();
					max_q.pop();
				}
				else
				{
					max_q.push(mid);
					mid=min_q.top();
					min_q.pop();
				}
			}
			cout<<'\n'<<mid;
		}
	}
	
	return 0;
}
