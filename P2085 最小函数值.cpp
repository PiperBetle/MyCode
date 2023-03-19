#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<queue>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
struct qw
{
	int A,B,C;
	int now,num;
	friend bool operator<(const qw a,const qw b)
	{   
		return a.num>b.num;
	}
};
priority_queue<qw>q;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m;
	qw t;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>t.A>>t.B>>t.C;
		t.now=1;
		t.num=t.A*t.now*t.now+t.B*t.now+t.C;
		q.push(t);
	}
	while(m--)
	{
		t=q.top();
		
		cout<<t.num<<' ';
		t.now++;
		t.num=t.A*t.now*t.now+t.B*t.now+t.C;
		
		q.pop();
		q.push(t);
	}
	
	return 0;
}
