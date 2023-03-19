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
int main()
{
	int a[31]={0},n,i;
	char aa[101];
	string st="PREDAJA";
	
	cin>>n;
	while(n--)
	{
		scanf("%s",aa);
		a[aa[0]-'a'+1]++;
	}
	for(i=1;i<=26;i++)
		if(a[i]>=5)
		{
			printf("%c",(char)(i+'a'-1));
			st="";
		}
	cout<<st;
	
    return 0;
}
