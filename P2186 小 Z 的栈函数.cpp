#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<string>
#include<vector>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
std::stack<int>s;
std::vector<std::pair<int,std::string> >a;
std::pair<int,std::string>t;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	for(;;)
	{
		cin>>t.second;
		if(t.second=="END")break;
		if(t.second=="NUM")cin>>t.first;
		a.emplace_back(t);
	}
	cin>>n;
	while(n--)
	{
		cin>>m;
		while(!s.empty())s.pop();
		s.push(m);
		for(auto it=a.begin();it!=a.end();it++)
			if(it->second=="NUM")
			{
				s.push(it->first);
			}
			else if(it->second=="POP")
			{
				if(s.empty())goto ERROR;
				s.pop();
			}
			else if(it->second=="INV")
			{
				if(s.empty())goto ERROR;
				m=s.top();s.pop();s.push(-m);
			}
			else if(it->second=="DUP")
			{
				if(s.empty())goto ERROR;
				s.push(s.top());
			}
			else if(it->second=="SWP")
			{
				if(s.size()<2)goto ERROR;
				int m1=s.top();s.pop();
				int m2=s.top();s.pop();
				s.push(m1);s.push(m2);
			}
			else if(it->second=="ADD")
			{
				if(s.size()<2)goto ERROR;
				m=s.top();s.pop();
				s.top()+=m;
				if(abs(s.top())>=1000000000)goto ERROR;
			}
			else if(it->second=="SUB")
			{
				if(s.size()<2)goto ERROR;
				m=s.top();s.pop();
				s.top()-=m;
				if(abs(s.top())>=1000000000)goto ERROR;
			}
			else if(it->second=="MUL")
			{
				if(s.size()<2)goto ERROR;
				m=s.top();s.pop();
				s.top()*=m;
				if(abs(s.top())>=1000000000)goto ERROR;
			}
			else if(it->second=="DIV")
			{
				if(s.size()<2)goto ERROR;
				m=s.top();s.pop();
				if(m==0)goto ERROR;
				s.top()/=m;
				if(abs(s.top())>=1000000000)goto ERROR;
			}
			else if(it->second=="MOD")
			{
				if(s.size()<2)goto ERROR;
				m=s.top();s.pop();
				if(m==0)goto ERROR;
				s.top()%=m;
				if(abs(s.top())>=1000000000)goto ERROR;
			}
		if(s.size()!=1)goto ERROR;
		cout<<s.top()<<'\n';continue;
		ERROR:cout<<"ERROR\n";
	}
	
	return 0;
}