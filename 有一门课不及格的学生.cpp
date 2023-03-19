#include<iostream>
using namespace std;
int main()
{
	int n,m;
	
	cin>>n>>m;
	if((n>60)&&(m<=60))cout<<1;
	else if((n<=60)&&(m>60))cout<<1;
	else cout<<0;
	
	return 0;
}
