#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string a[10001];
int main()
{
	int n,m,p;
	int i,t;
	
	for(i=1;i<=1000;i++)
	{
		t=i;
		a[i]="";
		a[i]+=t%10+'0';
		for(;;)
		{
			t/=10;
			if(t==0)break;
			a[i]+=t%10+'0';
		}
		reverse(a[i].begin(),a[i].end());
	}
	sort(a+1,a+1001);
	for(i=1;i<=1000;i++)cout<<a[i]<<'\n';
	
	return 0;
}
