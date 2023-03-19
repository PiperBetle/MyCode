#include<iostream>
using namespace std;
int main()
{
	int a,b;char c;
	
	cin>>a>>b>>c;
	if(!((c=='+')||(c=='-')||(c=='*')||(c=='/')))cout<<"Invalid operator!";
	else if((b==0)&&(c=='/'))cout<<"Divided by zero!";
	else
	{
		switch(c)
		{
			case '+':cout<<a+b;break;
			case '-':cout<<a-b;break;
			case '*':cout<<a*b;break;
			case '/':cout<<a/b;break;
		}
	}
	
	return 0;
}
