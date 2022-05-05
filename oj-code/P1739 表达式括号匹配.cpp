#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int sum=0;
	char c;
	
	for(;;)
	{
		cin>>c;
		if(c=='@')break;
		if(c=='(')sum++;
		if(c==')')
		{
			sum--;
			if(sum<0)break;
		}
	}
	if(sum==0)cout<<"YES";
	else cout<<"NO";
	
	return 0;
}

