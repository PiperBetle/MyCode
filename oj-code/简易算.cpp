#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

stack<char> op,num;

int main()
{
	int i,len;
	string s;
	char ch;
	double a,a1,a2;
	
	while(cin>>s)
	{
		if(s=="0")break;
		len=s.size();
		for(i=0;i<len;i++)
		{
			if(s[i]==' ')continue;
			else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
			{
				op.push(s[i]);
			}
			else
			{
				int a=0;
				while(s[i]>='0'&&s[i]<='9')
				{
					a=a*10+s[i]-'0';
					i++;
				}
				num.push((double)(a));
				i--;
			}
		}
		while(!op.empty())	
		{
			ch=op.top();
			a1=num.top();num.pop();
			a2=num.top();num.pop();
			if(ch=='+')
			{
				a2=a1+a2;
				num.push(a2);
			}
			if(ch=='-')
			{
				a2=a1-a2;
				num.push(a2);
			}
			if(ch=='*')
			{
				a2=a1*a2;
				num.push(a2);
			}
			if(ch=='/')
			{
				a2=a1/a2;
				num.push(a2);
			}
			printf("%.2lf\n",num.top());
		}
	}
	
	return 0;
} 
