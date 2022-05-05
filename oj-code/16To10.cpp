#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int to(char c)
{
	if(c-'0'<10)return c-'0';
	return c-'a';
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int ans=0;
	char c1,c2;
	
	while(cin>>c1>>c2)
	{
		cout<<"Öµ£º"<<to(c1)*16+to(c2)<<"  ×ÖÄ¸£º"<<(char)(to(c1)*16+to(c2))<<"\n";
	}
	
	return 0;
}
