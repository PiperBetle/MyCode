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
	
	cout<<"���棡ֻ����С��2^16-1��������km,m,dm,cm,mm��5����λ��ֻ���ȴ��С��������С����"<<endl; 
	while(1)
	{
		cout<<"��һ����:";
		cin>>a;
		cout<<"��һ����λ:";
		cin>>sa;
		cout<<"�ڶ�����:";
		cin>>b;
		cout<<"�ڶ�����λ:";
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
		cout<<"�����"<<a<<":"<<b<<endl;
	} 
	
	return 0;
} 
