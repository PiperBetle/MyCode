#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
	char a[1001];
	
	gets(a);
	if(a[0]=='-')cout<<"negative";
	else cout<<(a[0]?"positive":"zero");
	
	return 0;
}
