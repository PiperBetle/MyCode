#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
list<int> a;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k,now=0,len,t,n,m;
	char c;
	
	cin>>t;
	while(t--)
	{
		cin>>c;
		if(c=='A')
		{
			cin>>c;
			now++;
			if(c=='L')
			{
				a.push_front(now);
			}
			else
			{
				a.push_back(now);
			}
		}
		else
		{
			cin>>c;
			cin>>n;
			if(c=='L')
			{
				while(n--)
				{
					a.pop_front();
				}
			}
			else
			{
				while(n--)
				{
					a.pop_back();
				}
			}
		}
	}
	len=a.size();
	while(len--)
	{
		cout<<*(a.begin())<<endl;
		a.pop_front();
	}
	
	return 0;
}
