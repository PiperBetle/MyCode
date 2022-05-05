#include<iostream>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int a[10001];
int n,m,ans;
int main()
{
    double a,b,c,s;
    
    cin>>a>>b>>c;
    s=(a+b+c)/2;
	printf("%.1f",sqrt((s-a)*(s-b)*(s-c)*s));
    
    return 0;
}
