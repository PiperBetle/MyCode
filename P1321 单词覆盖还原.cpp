#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
string a;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int boy=0,girl=0,len;
	
	cin>>a;
	len=a.length();
	a+=".....";
	for(i=0;i<len;i++)
	{
		if((a[i]=='b')||(a[i+1]=='o')||(a[i+2]=='y'))boy++;
		if((a[i]=='g')||(a[i+1]=='i')||(a[i+2]=='r')||(a[i+3]=='l'))girl++;
	}
	cout<<boy<<endl<<girl;
	
	return 0;
}

