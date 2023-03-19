#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int m,t,s,a;

	cin>>m>>t>>s;
	if(t==0)cout<<0;
	else
	{
		a=s/t;
		if(s%t!=0)a++;
		cout<<max(m-a,0);
	}

	return 0;
}
