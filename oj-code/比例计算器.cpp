#include<iostream>
#include<string>
using namespace std;
int gcd(int a,int b)
{
	int r;
	do
	{
		r=a%b;
		a=b;
		b=r;
	}
	while(r==0);
	return b;
}
int main()
{
	int i,j;
	string sa,sb;
	int a,b,c;
	
	cout<<"警告！只限于小于2^16-1的整数和km,m,dm,cm,mm这5个单位！只能先大后小！可能有小错误！"<<endl; 
	while(1)
	{
		cout<<"第一个数:";
		cin>>a;
		cout<<"第一个单位:";
		cin>>sa;
		cout<<"第二个数:";
		cin>>b;
		cout<<"第二个单位:";
		cin>>sb;
		if(sa=="km")a*=100000;
		else if(sa=="m")a*=100;
		else if(sa=="dm")a*=10;
		else if(sa=="mm")a/=10.0;
		if(sb=="km")b*=100000;
		else if(sb=="m")b*=100;
		else if(sb=="dm")b*=10;
		else if(sb=="mm")b/=10.0;
		c=gcd((int)a,(int)b);
		a/=c;
		b/=c;
		cout<<"结果是"<<a<<":"<<b<<endl;
	} 
	
	return 0;
} 
