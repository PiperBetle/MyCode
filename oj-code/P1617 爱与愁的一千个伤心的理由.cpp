#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int n[11]={0};
string a[1011]={""};
string hundred="hundred";
string thousand="thousand";
int main()
{
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	a[0]="zero";
	a[1]="one";
	a[2]="two";
	a[3]="three";
	a[4]="four";
	a[5]="five";
	a[6]="six";
	a[7]="seven";
	a[8]="eight";
	a[9]="nine";
	a[10]="ten";
	a[11]="eleven";
	a[12]="twelve";
	a[13]="thirteen";
	a[14]="fourteen";
	a[15]="fifteen";
	a[16]="sixteen";
	a[17]="seventeen";
	a[18]="eighteen";
	a[19]="nineteen";
	a[20]="twenty";
	a[30]="thirty";
	a[40]="forty";
	a[50]="fifty";
	a[60]="sixty";
	a[70]="seventy";
	a[80]="eighty";
	a[90]="ninety";
	for(i=2;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			a[i*10+j]=a[i*10]+" "+a[j];
		}
	}
	cin>>n[0];
	n[5]=n[0];
	n[4]=n[0]%10;
	n[0]/=10;
	n[3]=n[0]%10;
	n[0]/=10;
	n[2]=n[0]%10;
	n[0]/10;
	n[1]=n[0];
	n[0]=n[5];
	if(n[0]<100)
	{
		cout<<a[n[0]];
		return 0;
	}
	if((99<n[0])&&(a[0]<1000))
	{
		cout<<a[3]<<" hundred ";
		if(n[3]==0)
		{
			cout<<a[1]
		}
	}
	
    return 0;
}
