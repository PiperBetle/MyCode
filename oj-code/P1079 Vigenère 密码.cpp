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
char vi(char x,char y)
{
	if(('A'<=y)&&(y<='Z'))
	{
		char z=y-x-'A';
		if(z<'A')z+=25;
		if('Z'<z)z-=25;
		return z;
	}
	else
	{
		char z=y-x-'a';
		if(z<'a')z+=25;
		if('z'<z)z-=25;
		return z;
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int la,lb;
	char a[10001],b[10001];
	
	scanf("%s%s",a,b);
	la=strlen(a);
	lb=strlen(b);
	for(i=0;i<la;i++)
	{
		if(('A'<=a[i])&&(a[i]<='Z'))
			a[i]=a[i]-'A'+'a';
	}
	for(i=0,j=0;i<lb;i++,j++)
	{
		j%=la;
		cout<<vi(a[j],b[i]);
	}
	
	return 0;
}
