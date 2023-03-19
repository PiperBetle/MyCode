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
	char c;
	
	for(;;)
	{
		c=getchar();
		if(c=='\n')return 0;
		putchar(c);
		if((c=='a')||(c=='o')||(c=='e')||(c=='i')||(c=='u'))
		{
			getchar();
			getchar();
		}
	}
	
    return 0;
}
