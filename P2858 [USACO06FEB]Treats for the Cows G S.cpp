#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	for(i=0;i<=500;i++)
	{
		cout<<"����("<<i<<"/20)\n";
	}
	
	
	for(i=0;i<=500;i++)
	{
		cout<<"������"<<i<<"��\n";
		if(i!=500)cout<<"������"<<i<<".5��\n";
	}
	
	return 0;
}

