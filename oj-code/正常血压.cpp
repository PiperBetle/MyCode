#include<iostream>
using namespace std;
int main()
{
	int t,i,a,b,n,max=-1;
	
	cin>>n;
	t=0;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		if((a>=90)&&(a<=140)&&(b>=60)&&(b<=90))t++;
		else
		{
			if(t>max)max=t;
			t=0;
		}
	}
	if(t>max)max=t;
	t=0;
	cout<<max;
	
	return 0;
}
