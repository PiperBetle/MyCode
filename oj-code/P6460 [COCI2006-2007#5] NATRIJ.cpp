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
	int a1,a2,a3,b1,b2,b3;
	
	scanf("%d:%d:%d",&a1,&a2,&a3);
	scanf("%d:%d:%d",&b1,&b2,&b3);
	
	if((b1<a1)||((b1==a1)&&(b2<a2))||((b1==a1)&&(b2==a2)&&(b3<=a3)))b1+=24;
	if(b3<a3)
	{
		b2--;
		b3+=60;
	}
	if(b2<a2)
	{
		b1--;
		b2+=60;
	}
	printf("%02d:%02d:%02d",b1-a1,b2-a2,b3-a3);
	
    return 0;
}
