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
inline int read()
{
	int w=0,y=1;char c;
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=(w<<1)+(w<<3)+(c^48);
	return w*y;
}
signed main()
{
	freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T=read();
	
	while(T--)
	{
		while(!max_q.empty())max_q.pop();
		while(!min_q.empty())min_q.pop();
		m=0;
		while(n=read())
		{
			if(n==0)break;
			if(n==-1)
			{
				if(m&1)cout<<min_q.top()<<'\n',min_q.pop();
				else cout<<max_q.top()<<'\n',max_q.pop();
				m--;
			}
			else
			{
				if(min_q.empty()||n>min_q.top())min_q.push(n);
				else max_q.push(n);
				m++;
				if((m&1)&&max_q.size()>min_q.size())min_q.push(max_q.top()),max_q.pop();
				else if(!(m&1)&&max_q.size()<min_q.size())max_q.push(min_q.top()),min_q.pop();
			}
		}
	}
	
	return 0;
}