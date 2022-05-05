#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define MOD 1000000007
using namespace std;
stack<int> num,op;
int level(char c)
{
	if(c=='*')return 2;
	if(c=='^')return 3;
	return 1;
}
int qp(int a,int p,int k)
{
	if(p==0)
		return 1;
	int t=1;
	for(;p;p>>=1,t=t*t%k)
		if(p&1)
			t=t*a%p;
	return t;
}
void calc()
{
	int x1=num.top();
	num.pop();
	int x2=num.top();
	num.pop();
	switch(op.top())
	{
		case '+':
			num.push(x2+x1);
			break;
		case '-':
			num.push((x2-x1+MOD)%MOD);
			break;
		case '*':
			num.push(x2*x1%MOD);
			break;
		case '^':
			num.push(qp(x2,x1,MOD));
			break;
	}
	op.pop();
}
int read()
{
	string s="";
	char c;
	while(c=='\n'||c=='\r'||c==' '&&c!='@')
		c=getchar();
	while(c!='\n'&&c!='\r'&&c!=EOF&&c!='@')
	{
		if(c!=' ')
			s+=c;
		c=getchar();
	}
	int len=s.length();
	int X=0;
	for(int i=1;i<len;i++)
	{
		if(s[i]=='a')
			num.push(211);
		else if(isdigit(s[i]))
		{
			X=X*10+s[i]-'0';
			if(i==len-1||!isdigit(s[i+1]))
			{
				num.push(X);
				X=0;
			}
		}
		else if(s[i]=='(')
			op.push('(');
		else if(s[i]==')')
		{
			while(!op.empty()&&op.top()!='(')
				calc();
			if(!op.empty()&&op.top()=='(')
				op.pop();
		}
		else
		{
			while(!op.empty()&&level(s[i])<=level(op.top()))
				calc();
			op.push(s[i]);
		}
	}
	while(!op.empty())
		if(op.top()=='(')
			op.pop();
		else
			calc();
	return num.top();
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	
	
	return 0;
}