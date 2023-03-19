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
	long long n,m,x=0,y=0,nn,mm;
	
	cin>>n>>m;
	nn=n;
	mm=m;
	for(;;)
	{
		if((nn>0)&&(mm>0))x=x+nn*mm;
		else break;
		nn--;
		mm--;
	}
	y=n*(n+1)/2*m*(m+1)/2;
	y-=x;
	cout<<x<<" "<<y;
	
    return 0;
}
