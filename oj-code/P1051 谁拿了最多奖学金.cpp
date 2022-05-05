#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
using namespace std;
struct st
{
	string name;
	int mark;
};
st a[101];
int main()
{
	int n,i,j,k,sum=0,x,y,z;
	char c,q,w;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].name;
		cin>>x>>y>>q>>w>>z;
		if((x>80)&&(z>0))a[i].mark+=8000;
		if((x>85)&&(y>80))a[i].mark+=4000;
		if(x>90)a[i].mark+=2000;
		if((x>85)&&(w=='Y'))a[i].mark+=1000;
		if((y>80)&&(q=='Y'))a[i].mark+=850;
		sum+=a[i].mark;
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j].mark<a[j+1].mark)
			{
				swap(a[j].mark,a[j+1].mark);
				swap(a[j].name,a[j+1].name);
			}
		}
	}
	cout<<a[1].name<<endl<<a[1].mark<<endl<<sum;
	
	return 0;
}
