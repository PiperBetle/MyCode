#include<iostream>
using namespace std;
int main()
{
	int i,j,s,e,ans;
	
	cin>>s>>e;
	for(;s<=e;s++)
		if(s%17==0)ans+=s;
	cout<<ans;
	
	return 0;
} 
