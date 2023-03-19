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
#include<list>
using namespace std;
int main()
{
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	string tem,str,id;
	int t,len,idnum,tick,n;
	
	
	cin>>t>>n;
	cin>>str;
	while(t--)
	{
		tick=0;
		cin>>id>>tem;
		idnum=0;
		j=1;
		for(i=0;i<=15;i++)
		{
			idnum=idnum*2+id[i]-'0';
		}
		if((1<=idnum)&&(idnum<=10000))
		{
			printf("ID: %d\n",idnum);
			if((id[15]=='1'&&tem=="01")||(id[15]=='0'&&tem=="10"))puts("Type Correct");
			else puts("Type Incorrect");
			for(i=0;i<n;i++)
			{
				cin>>tem;
				if((str[i]=='A')&&(tem=="1000"))tick++;
				if((str[i]=='B')&&(tem=="0100"))tick++;
				if((str[i]=='C')&&(tem=="0010"))tick++;
				if((str[i]=='D')&&(tem=="0001"))tick++;
			}
			tick*=100;
			printf("%.1f\n\n",(double)((double)tick/(double)n));
		}
		else
		{
			printf("Wrong ID\n\n");
			for(i=1;i<=n;i++)cin>>tem;
		}
	}
	
	return 0;
}
