#include<iostream>
using namespace std;
int main()
{
	int a,b,c,i,aa,bb,cc;
	
	cin>>a>>b>>c;
	for(i=2;;i++)
	{
		aa=a%i;
		bb=b%i;
		cc=c%i;
		if((aa==bb)&&(bb==cc))
		{
			cout<<i;
			break;
		}
	}
	
	return 0;
}
