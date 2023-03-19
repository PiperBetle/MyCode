#include<iostream>
using namespace std;
int main()
{
	int a,b,i,c=1;
	
	cin>>a>>b;
	for(i=1;i<=b;i++)
	{
		c=c*a;
	}
	switch(c%7)
	{
		case 0:cout<<"Sunday";break;
		case 1:cout<<"Monday";break;
		case 2:cout<<"Tuesday";break;
		case 3:cout<<"Wednesday";break;
		case 4:cout<<"Thurday";break;
		case 5:cout<<"Friday";break;
		case 6:cout<<"Saturday";break;
	}
	
	return 0;
}
