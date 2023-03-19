#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct st
{
	int number;
	int a;
	int b;
};
int main()
{
	st a[1001];
	int n,i,flag;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].number>>a[i].a>>a[i].b;
		flag=0;
		if((a[i].a+a[i].b)>140)flag++;
		if((0.7*a[i].a+0.3*a[i].b)>=80)flag++;
		if(flag==2)cout<<"Excellent"<<endl;
		else cout<<"Not excellent"<<endl;
	}
	
	return 0;
}

