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
	
	int n;
	cin>>n;
	
	if(n==3)cout<<"1+2-3\n";
	if(n==4)cout<<"1-2-3+4\n";
	if(n==5)cout<<"1 2-3-4-5\n";
	if(n==6)cout<<"1 2+3-4-5-6\n";
	if(n==7)cout<<"1+2-3+4-5-6+7\n1+2-3-4+5+6-7\n1-2 3+4+5+6+7\n1-2 3-4 5+6 7\n1-2+3+4-5+6-7\n1-2-3-4-5+6+7\n";
	if(n==8)cout<<"1 2-3 4-5 6+7 8\n1+2 3-4 5+6+7+8\n1+2+3+4-5-6-7+8\n1+2+3-4+5-6+7-8\n1+2-3+4+5+6-7-8\n1+2-3-4-5-6+7+8\n1-2 3-4+5+6+7+8\n1-2+3-4-5+6-7+8\n1-2-3+4+5-6-7+8\n1-2-3+4-5+6+7-8\n";
	if(n==9)cout<<"1 2+3 4-5 6-7+8+9\n1 2+3+4-5-6-7+8-9\n1 2+3-4 5+6+7+8+9\n1 2+3-4+5-6+7-8-9\n1 2-3+4+5 6-7 8+9\n1 2-3+4+5+6-7-8-9\n1 2-3-4-5+6-7-8+9\n1 2-3-4-5-6+7+8-9\n1+2-3 4-5 6+7 8+9\n1-2 3-4-5 6-7+8 9\n1-2-3 4+5+6+7+8+9\n";
	
	return 0;
}
