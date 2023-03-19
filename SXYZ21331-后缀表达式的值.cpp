#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#define int long long
using namespace std;
stack<int>a;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m=0,t;
	int t1,t2;
	
	char c=getchar();
	while(c!='@')
	{
		switch(c)
		{
			case '+':t1=a.top();a.pop();t2=a.top();a.pop();a.push(t2+t1);break;
			case '-':t1=a.top();a.pop();t2=a.top();a.pop();a.push(t2-t1);break;
			case '*':t1=a.top();a.pop();t2=a.top();a.pop();a.push(t2*t1);break;
			case '/':t1=a.top();a.pop();t2=a.top();a.pop();a.push(t2/t1);break;
			case ' ':a.push(m);m=0;break;
			default:m=m*10+c-'0';
		}
		c=getchar();
	}
	cout<<a.top()<<'\n';
	
    return 0;
}