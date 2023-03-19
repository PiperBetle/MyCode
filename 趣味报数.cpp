#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	int i,j,n,a,b,m,c,ans,s;
	
	cin>>n>>a>>b;
	c=a/gcd(a,b)*b;
	s=n/c*(a<b?a:b);
	s+=(n%c<(a<b?a:b)?n%c:(a<b?a:b));
	cout<<s;
	
	return 0;
} 
