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
	string a,b;
	int la,lb,i;
	char c;
	
	cin>>a>>c>>b;
    la=a.length();
    lb=b.length();
	if(c=='+')
	{
		if(la==lb)
		{
			putchar('2');
			for(i=1;i<=la-1;i++)putchar('0');
		}
		else
		{
			if(la<lb)swap(la,lb);
			putchar('1');
			for(i=2;i<=la;i++)
			{
				if(i+lb-1==la)putchar('1');
				else putchar('0');
			}
		}
	}
	else
	{
		putchar('1');
		for(i=1;i<=la+lb-2;i++)putchar('0');
	}
	
    return 0;
}
