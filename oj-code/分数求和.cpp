#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	int i,j,n;
	int a,b,m,t,tt;
	char fs[5];
	int fz,fm,sumfz=1,sumfm=1;
	
	cin>>m;
	getchar();
	while(m--)
	{
		for(i=0;i<=4;i++)fs[i]='/';
		gets(fs);
		t=strlen(fs);
		if(t==3)
		{
			fz=fs[0]-'0';
			fm=fs[2]-'0';
		}
		else
		{
			if(t==5)fz=fm=10;
			else
			{
				if(fs[1]=='0')
				{
					fz=10;
					fm=fs[3]-'0';
				}
				else
				{
					fz=fs[0]-'0';
					fm=10;
				}
			}
		}
		t=gcd(fm,sumfm);
		tt=fm*sumfm/t;
		fz=fz*tt/fm;
		sumfz=sumfz*tt/sumfm;
		sumfm=fm=tt;
		sumfz=sumfz+fz;
		t=gcd(sumfz,sumfm);
		sumfz=sumfz/t;
		sumfm=sumfm/t;
		
	}
	sumfz=sumfz-sumfm;
	t=gcd(sumfz,sumfm);
	sumfz=sumfz/t;
	sumfm=sumfm/t;
	cout<<sumfz;
	if(sumfm!=1)
		cout<<'/'<<sumfm;
	
	return 0;
}
