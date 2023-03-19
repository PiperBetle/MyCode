#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
std::priority_queue<int,std::vector<int> >max_q;
std::priority_queue<int,std::vector<int>,std::greater<int> >min_q;
std::string s;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m=0,T;
	
	cin>>T;
	while(T--)
	{
		cin>>n;m++;
		if(min_q.empty()||n>min_q.top())min_q.push(n);else max_q.push(n);
		if((m&1)&&max_q.size()>min_q.size())min_q.push(max_q.top()),max_q.pop();
		else if(!(m&1)&&max_q.size()<min_q.size())max_q.push(min_q.top()),min_q.pop();
	}
	cin>>T;
	while(T--)
	{
		cin>>s;
		if(s=="mid")
		{
			if(m&1)cout<<min_q.top()<<'\n';
			else cout<<max_q.top()<<'\n';
		}
		else
		{
			cin>>n;m++;
			if(min_q.empty()||n>min_q.top())min_q.push(n);else max_q.push(n);
			if((m&1)&&max_q.size()>min_q.size())min_q.push(max_q.top()),max_q.pop();
			else if(!(m&1)&&max_q.size()<min_q.size())max_q.push(min_q.top()),min_q.pop();
		}
	}
	
	return 0;
}
