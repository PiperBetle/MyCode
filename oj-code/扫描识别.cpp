#include<iostream>
using namespace std;
int main()
{
	int i,j,n,m,k,s=0,sum=0;
	char a[2000],str[200];
	
	for(i=1;i<255;i++)a[i]=i;
	a['O']='0';
	a['l']='1';
	a['Z']='2';
	a['S']='5';
	a['b']='6';
	a['B']='8';
	a['q']='9';
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
	{
		putchar(a[str[i]]);
	}
	cout<<endl;
	
	return 0;
} 
