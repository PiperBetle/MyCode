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
		cout<<"拉黑("<<i<<"/20)\n";
	}
	
	
	for(i=0;i<=500;i++)
	{
		cout<<"可能是"<<i<<"分\n";
		if(i!=500)cout<<"可能是"<<i<<".5分\n";
	}
	
	return 0;
}

