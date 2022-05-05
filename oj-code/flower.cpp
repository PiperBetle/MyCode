#include<iostream>
#include<string>
using namespace std;
char a[2000][2000];
int main()
{
	int i,j,k,b,c,ans,flag=0,n;
	string str;
	
	cin>>n>>str;
	for(i=0;i<n;i++)
	{
		for(j=i;j<=2*n-2-i;j++)
		{
			a[i][j]=str[i];
			a[2*n-2-i][j]=str[i];
			a[j][i]=str[i];
			a[j][2*n-2-i]=str[i];
		}
		a[i][2*n-1]='\0';
		a[2*n-2-i][2*n-1]='\0';
	}
	for(i=0;i<2*n-1;i++)
		puts(a[i]);
	
	return 0;
} 
