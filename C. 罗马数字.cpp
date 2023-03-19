#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a,b,c,d;
int main()
{
	string ans="";
	
	cin>>a;
	d=a%10;
	a/=10;
	c=a%10;
	a/=10;
	b=a%10;
	a/=10;
//	cout<<a<<b<<c<<d;
	switch(a)
	{
		case 1:ans+="M";break;
		case 2:ans+="MM";break;
		case 3:ans+="MMM";break;
	}
	switch(b)
	{
		case 1:ans+="C";break;
		case 2:ans+="CC";break;
		case 3:ans+="CCC";break;
		case 4:ans+="CD";break;
		case 5:ans+="D";break;
		case 6:ans+="DC";break;
		case 7:ans+="DCC";break;
		case 8:ans+="DCCC";break;
		case 9:ans+="CM";break;
	}
	switch(c)
	{
		case 1:ans+="X";break;
		case 2:ans+="XX";break;
		case 3:ans+="XXX";break;
		case 4:ans+="XI";break;
		case 5:ans+="I";break;
		case 6:ans+="IX";break;
		case 7:ans+="IXX";break;
		case 8:ans+="IXXX";break;
		case 9:ans+="XC";break;
	}
	switch(d)
	{
		case 1:ans+="I";break;
		case 2:ans+="II";break;
		case 3:ans+="III";break;
		case 4:ans+="IV";break;
		case 5:ans+="V";break;
		case 6:ans+="VI";break;
		case 7:ans+="VII";break;
		case 8:ans+="VIII";break;
		case 9:ans+="IX";break;
	}
	cout<<ans;
	
	return 0;
}
