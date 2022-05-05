#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
struct st
{
	string name;
	int mark;
	int Chinese;
	int mathematics;
	int English;
};
int main()
{
	int i,j,k,m,n,t,l;
	st a[1001];
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].name>>a[i].Chinese>>a[i].mathematics>>a[i].English;
		a[i].mark=a[i].Chinese+a[i].mathematics+a[i].English;
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j].mark<a[j+1].mark)
			{
				swap(a[j].mark,a[j+1].mark);
				swap(a[j].name,a[j+1].name);
				swap(a[j].Chinese,a[j+1].Chinese);
				swap(a[j].mathematics,a[j+1].mathematics);
				swap(a[j].English,a[j+1].English);
			}
		}
	}
	cout<<a[1].name<<" "<<a[1].Chinese<<" "<<a[1].mathematics<<" "<<a[1].English;
	
	return 0;
}
